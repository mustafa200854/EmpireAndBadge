#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BusinessDataAsset.h"
#include "BusinessComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EMPIREANDBADGE_API UBusinessComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UBusinessComponent();

	UFUNCTION(BlueprintCallable)
	void StartBusiness(UBusinessDataAsset* BusinessData);

	UFUNCTION(BlueprintCallable)
	void HireStaff(int32 Amount);

	UFUNCTION(BlueprintCallable)
	void UpgradeBusiness(int32 Level);

	UFUNCTION(BlueprintCallable)
	float GetCurrentRevenue() const;

protected:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY()
	UBusinessDataAsset* CurrentBusinessData;

	UPROPERTY(EditAnywhere)
	float CurrentRevenuePerSecond;

	UPROPERTY(EditAnywhere)
	int32 CurrentStaff;

	UPROPERTY(EditAnywhere)
	int32 UpgradeLevel;

	float AccumulatedRevenue;
	float HeatGeneration;
};