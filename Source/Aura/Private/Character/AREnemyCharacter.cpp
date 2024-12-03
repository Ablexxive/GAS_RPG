// Copyright Throne


#include "Character/AREnemyCharacter.h"
#include "AbilitySystem/ARAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

#include "Aura/Aura.h"

AAREnemyCharacter::AAREnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UARAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAREnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_HIGHLIGHT);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_HIGHLIGHT);
	
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AAREnemyCharacter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	Weapon->SetRenderCustomDepth(true);
	
	isHighlighted = true;
}

void AAREnemyCharacter::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
	
	isHighlighted = false;	
}

