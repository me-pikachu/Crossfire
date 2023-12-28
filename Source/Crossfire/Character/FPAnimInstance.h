// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FPAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class CROSSFIRE_API UFPAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override; // override means that any other function of the same name would be over rided by this function
	virtual void NativeUpdateAnimation(float DeltaTime) override;

private:
	UPROPERTY(BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
	class AFPCharacter* FPCharacter; // AFPCharacter is a class name not a class instance so to tell the compiler that it is a class name
	// not a variable we used class before AFPCharacter*

	UPROPERTY(BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	float Speed; // it indicates the speed in the x-y plane

	UPROPERTY(BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bIsInAir; // is in the air or not

	UPROPERTY(BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bIsAcc; // indicates whether the movement key (w,a,s,d) is pressed or not
};
