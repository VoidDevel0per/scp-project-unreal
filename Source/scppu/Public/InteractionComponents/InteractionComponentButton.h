

#pragma once

#include "CoreMinimal.h"
#include "InteractionComponents/InteractionComponentBase.h"
#include "InteractionComponentButton.generated.h"

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInteractionComponentButtonIntertact, APawn*, Interactor, UObject*, Item);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SCPPU_API UInteractionComponentButton : public UInteractionComponentBase
{
	GENERATED_BODY()
	
	//// Properties ////
public:
	UPROPERTY(BlueprintAssignable)
		FInteractionComponentButtonIntertact OnInteract;

	//// Functions ////	
public:
		virtual bool StartInteraction(APawn* Interactor, UObject* Item) override;

		virtual bool EndInteraction(APawn* Interactor) override;
};
