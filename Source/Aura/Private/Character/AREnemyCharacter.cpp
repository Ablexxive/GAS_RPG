// Copyright Throne


#include "Character/AREnemyCharacter.h"

#include "Aura/Aura.h"

void AAREnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_HIGHLIGHT);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_HIGHLIGHT);
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

