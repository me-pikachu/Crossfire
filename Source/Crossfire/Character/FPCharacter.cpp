#include "FPCharacter.h"
//#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AFPCharacter::AFPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; // b before canevertick is to indicate that it is of type bool

	/*
	//These are for third person view
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetMesh()); // This connects the CameraBoom to the mesh so when the capsule size changes CameraBoom also shifts (during crouches)
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->bUsePawnControlRotation = true; // Camera Boom would rotate with the player
	FPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPCamera"));
	FPCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FPCamera->bUsePawnControlRotation = false;
	*/

	/*
	//These are for first person view
	FPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPCamera"));
	FPCamera->SetupAttachment(GetMesh(), TEXT("head"));
	FPCamera->bUsePawnControlRotation = true;
	*/

}

// Called when the game starts or when spawned
void AFPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void AFPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPCharacter::Jump);
	// Binding the inputs to their respective functions (func pointer)
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AFPCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPCharacter::LookUp);
	
}

void AFPCharacter::MoveForward(float value)
{
	// there is a function AddMovementInput which takes one argument as FVector and other is the float value
	// it moves in the direction of the FVector
	AddMovementInput(GetActorForwardVector(), value); // forward vector is the x direction of the actor
	/*
	In third person we need to move to the forward direction of the controller
	// FRotator Comprises of three inputs first of which is pitch (vertical movement or perpendicular to Y axis)
	// second is yaw (horizontal movement or perpendicular to Z axis) and the thrid is roll (which is the rotation of the screen or perpendicular to X axis)
	// Firstly making an FVector
	if (Controller != nullptr && value != 0.f){
		FRotator yawrotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		FVector dirtomove(FRotationMatrix(yawrotation).GetUnitAxis(EAxis::X)); // FRotationMatrix converts the FRotator into a Matrix
		AddMovementInput(dirtomove, value);
	}
	*/

}

void AFPCharacter::MoveRight(float value)
{
	// Unreal engines uses left hand co-ordinate system
	AddMovementInput(GetActorRightVector(), value); // right vector is the y direction of the vector
	/*
	In third person we need to move to the forward direction of the controller
	// FRotator Comprises of three inputs first of which is pitch (vertical movement or perpendicular to Y axis)
	// second is yaw (horizontal movement or perpendicular to Z axis) and the thrid is roll (which is the rotation of the screen or perpendicular to X axis)
	// Firstly making an FVector
	if (Controller != nullptr && value != 0.f){
		FRotator yawrotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		FVector dirtomove(FRotationMatrix(yawrotation).GetUnitAxis(EAxis::Y)); // FRotationMatrix converts the FRotator into a Matrix
		AddMovementInput(dirtomove, value);
	}
	*/
}

void AFPCharacter::Turn(float value)
{
	AddControllerYawInput(value);
}

void AFPCharacter::LookUp(float value)
{
	AddControllerPitchInput(value);
}

// Called every frame
void AFPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




