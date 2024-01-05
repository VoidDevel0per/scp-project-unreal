#include "AI/Character/StealthAI.h"

// Sets default values
AStealthAI::AStealthAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStealthAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStealthAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AStealthAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Retrieves the location and rotation of the eye socket variable.
 void AStealthAI::GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const
{
	Location = GetMesh()->GetSocketLocation(EyeSocket);
	Rotation = GetMesh()->GetSocketRotation(EyeSocket);
}
