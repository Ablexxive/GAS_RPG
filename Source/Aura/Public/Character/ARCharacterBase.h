// Copyright Throne

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ARCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AARCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AARCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
