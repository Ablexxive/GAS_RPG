// Copyright Throne

#pragma once

#include "CoreMinimal.h"
#include "Character/ARCharacterBase.h"
#include "Interaction/InteractionInterface.h"
#include "AREnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAREnemyCharacter : public AARCharacterBase, public IInteractionInterface
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
	// Interaction Interface Functions
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isHighlighted = false;
};
