// Copyright Throne


#include "Player/ARPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/InteractionInterface.h"

AARPlayerController::AARPlayerController()
{
	bReplicates = true;
}

void AARPlayerController::PlayerTick(float DeltaSeconds)
{
	Super::PlayerTick(DeltaSeconds);

	CursorTrace();
	
}

void AARPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(AuraContext, 0);	
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AARPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AARPlayerController::Move);
}

void AARPlayerController::Move(const FInputActionValue& InputActionValue)
{
	// We want forward direction based on the view of the controller to the player, not player facing!
	// So we get the controller rotation, figure out Yaw, then get unit vectors for forward/right from that yaw rotation.
	const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// Apply input movement values
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AARPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	//GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	GetHitResultUnderCursor(ECC_Pawn, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor(); // because we are using TScriptInterface, we don't have to cast manually.

	if (ThisActor.GetInterface() == nullptr)
	{
		if (LastActor.GetInterface() != nullptr)
		{
			LastActor->UnHighlightActor();
		}
	}
	else
	{
		ThisActor->HighlightActor();
	}
	/*
	if (ThisActor != nullptr (ThisActor != LastActor))
	{
		if (LastActor)
		{
			LastActor->UnHighlightActor();
		}
		ThisActor->HighlightActor();
	}
	*/
	// If ThisActor == Last Actor, or if n
	//if (!LastActor && !ThisActor) return;
}
