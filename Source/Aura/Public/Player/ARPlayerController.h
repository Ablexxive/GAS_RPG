// Copyright Throne

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ARPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class IInteractionInterface;

UCLASS()
class AURA_API AARPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AARPlayerController();
	virtual void PlayerTick(float DeltaSeconds) override;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	// By putting "struct" we forward decalare it. Since it's a struct and not
	// a class, we can do it here.
	void Move(const struct FInputActionValue& InputActionValue);

	// Highlighting
	void CursorTrace();
	TScriptInterface<IInteractionInterface> LastActor;
	TScriptInterface<IInteractionInterface> ThisActor;	
};
