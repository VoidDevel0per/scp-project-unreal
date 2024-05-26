#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SCP_914Structs.generated.h"


class ABaseItem;

UENUM(BlueprintType)
enum class EClockworkMachineSetting : uint8
{
	Rough,
	Coarse,
	OneToOne,
	Fine,
	VeryFine,
};


USTRUCT(BlueprintType)
struct FClockworksRecipes : public FTableRowBase
{
	GENERATED_BODY()


public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EClockworkMachineSetting Setting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSet<TSubclassOf<ABaseItem>> InputItemClasses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf <ABaseItem> OutputItemClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<EClockworkMachineSetting, float> RecipeSelectionProbability;
};