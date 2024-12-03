// Copyright Throne

#pragma once

#include "CoreMinimal.h"
#include "Character/ARCharacterBase.h"
#include "ARPlayerCharacter.generated.h"

UCLASS()
class AURA_API AARPlayerCharacter : public AARCharacterBase
{
	GENERATED_BODY()
public:
	AARPlayerCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};

