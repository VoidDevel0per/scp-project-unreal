#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "Engine/DataTable.h"
#include "AIParams.generated.h"

USTRUCT(BlueprintType)
struct FAIParams : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBlackboardData* BlackBoard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanChasePlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bAdjustSpeedOnDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DefaultWalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ChaseSpeed;
};
