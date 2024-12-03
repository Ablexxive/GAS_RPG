// Copyright Throne


#include "Player/ARPlayerState.h"

#include "AbilitySystem/ARAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AARPlayerState::AARPlayerState()
{
	NetUpdateFrequency = 100.f;
	AbilitySystemComponent = CreateDefaultSubobject<UARAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AARPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
