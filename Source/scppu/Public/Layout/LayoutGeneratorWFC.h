

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Layout/LayoutStructs.h"
#include "LayoutGeneratorWFC.generated.h"

class ALayout;

UCLASS(Blueprintable)
class SCPPU_API ULayoutGeneratorWFC : public UObject
{
	GENERATED_BODY()

protected:
	struct FWavefunctionPossibility
	{
	public:
		FName RowName;
		int32 Rotation;

		FWavefunctionPossibility(FName InRowName, int32 InRotation)
		{
			this->RowName = InRowName;
			this->Rotation = InRotation;
		}
	};

public:
	//// Properties ////
	
public:
	//// Functions ////
	UFUNCTION(BlueprintCallable)
		bool GenerateLayout(ALayout* Layout, int32 NewSeed);

	UFUNCTION(BlueprintCallable)
		void AsyncGenerateLayout(ALayout* Layout, int32 NewSeed);
};
