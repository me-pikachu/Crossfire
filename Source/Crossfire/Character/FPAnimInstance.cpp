// Fill out your copyright notice in the Description page of Project Settings.


#include "FPAnimInstance.h"
#include "FPCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UFPAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation(); // calling the super function
	// actually our current FPAnimInstance is base class of AnimInstance(Parent Class)
	// So by writing Super:: we are calling the function of AnimInstance

	FPCharacter = Cast<AFPCharacter>(TryGetPawnOwner()); // TryGetPawnOwner returns a pawn

}

void UFPAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	// updating the variables now
	if (FPCharacter == nullptr) {
		FPCharacter = Cast<AFPCharacter>(TryGetPawnOwner()); // TryGetPawnOwner returns a pawn
	}

	if (FPCharacter == nullptr) return;

	// fetching the velocity for speed
	FVector vel = FPCharacter->GetVelocity();
	vel.Z = 0; // needs speed only in xy plane
	Speed = vel.Size(); // .size returns the magnitude of the vector

	bIsInAir = FPCharacter->GetCharacterMovement()->IsFalling();

	bIsAcc = FPCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false; // GetCurrentAcceleration returns a vector of the acceleration




}
