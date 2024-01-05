

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/AudioComponent.h"
#include "StealthAI.generated.h"

UCLASS()
class SCPPU_API AStealthAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AStealthAI();


	// Overrides the base class's virtual function for getting the actor's eye viewpoint.
	virtual void GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName EyeSocket;

};
