// Copyright Throne


#include "Character/ARPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/ARPlayerState.h"

AARPlayerCharacter::AARPlayerCharacter()
{
	UCharacterMovementComponent* CMC = GetCharacterMovement();
	CMC->bOrientRotationToMovement = true;
	CMC->RotationRate = FRotator(0.f, 400.f, 0.f);
	CMC->bConstrainToPlane = true;
	CMC->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AARPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	// for the server
	InitAbilityActorInfo();
}

void AARPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// for client
	InitAbilityActorInfo();
}

void AARPlayerCharacter::InitAbilityActorInfo()
{
	const AController* MyController = GetController();
	
	AARPlayerState* ARPlayerState = MyController->GetPlayerState<AARPlayerState>();
	AbilitySystemComponent = ARPlayerState->GetAbilitySystemComponent();
	AttributeSet = ARPlayerState->GetAttributeSet();

	AbilitySystemComponent->InitAbilityActorInfo(ARPlayerState, this);
}
