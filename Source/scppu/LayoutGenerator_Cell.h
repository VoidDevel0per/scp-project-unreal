

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LayoutGenerator_Structs.h"
#include "LayoutGenerator_Cell.generated.h"

class ULevelStreamingDynamic;
class ALayoutGenerator_Main;

UINTERFACE(MinimalAPI)
class ULayoutGenerator_ReceiveCellInterface : public UInterface
{
	GENERATED_BODY()
};

class ILayoutGenerator_ReceiveCellInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category = "Layout Generator")
		void OnCellReceived(ULayoutGenerator_Cell* Cell, FRandomStream UniqueRandomStream);
};

UCLASS()
class SCPPU_API ULayoutGenerator_Cell : public UObject
{
	GENERATED_BODY()

public:

	friend class ALayoutGenerator_Main;

	//// FUNCTIONS ////

	UFUNCTION(BlueprintCallable, BlueprintPure)
		FVector GetWorldLocation();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		FRotator GetWorldRotation();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		FString GetUniqueName();

	UFUNCTION(BlueprintCallable)
		bool LoadLevel();

	UFUNCTION(BlueprintCallable)
		bool UnloadLevel();

	UFUNCTION(BlueprintCallable)
		void GetAllActorsInLevel(TArray<AActor*>& OutActors);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsPointInLevelBounds(FVector Point);

	//// PROPERTIES ////

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Transform")
		FIntVector2D Location;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Transform", meta = (ClampMin = "0", ClampMax = "3"))
		int32 Rotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
		ALayoutGenerator_Main* LayoutGenerator;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
		TSoftObjectPtr<UWorld> LevelAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "References")
		ULevelStreamingDynamic* LevelStreamingDynamic;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Properties")
		FRandomStream CellSeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Properties")
		FName RoomRowName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Properties")
		bool bIsGenerated = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Properties")
		bool bIsEnabled = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Properties")
		FCellSides HasDoor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Properties")
		FCellSides ShouldDisableNeighbour;

protected:
	virtual void BeginDestroy() override;

	//// FUNCTIONS ////

	void DrawCellDebug();

	UFUNCTION()
		bool SetRoom(const FName NewRoomRowName, const bool bForce);

	UFUNCTION()
		void OnLevelLoaded();
};