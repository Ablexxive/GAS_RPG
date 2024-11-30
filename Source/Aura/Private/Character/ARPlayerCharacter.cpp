// Copyright Throne


#include "Character/ARPlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

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
