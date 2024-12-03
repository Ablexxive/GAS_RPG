// Copyright Throne

#include "Character/ARCharacterBase.h"

AARCharacterBase::AARCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AARCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AARCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}
