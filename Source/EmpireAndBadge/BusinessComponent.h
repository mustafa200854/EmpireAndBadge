#pragma once

#include "CoreMinimal.h"
#include "BusinessComponent.generated.h"

UCLASS()
class EMPIREANDBADGE_API UBusinessComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void StartClubBusiness(FString ClubName);

	UPROPERTY(EditAnywhere)
	float DailyRevenue;
};