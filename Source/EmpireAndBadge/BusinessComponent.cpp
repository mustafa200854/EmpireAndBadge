#include "BusinessComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UBusinessComponent::UBusinessComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentRevenuePerSecond = 0.0f;
	CurrentStaff = 0;
	UpgradeLevel = 1;
	AccumulatedRevenue = 0.0f;
	HeatGeneration = 0.0f;
}

void UBusinessComponent::StartBusiness(UBusinessDataAsset* BusinessData)
{
	if (!BusinessData) return;

	CurrentBusinessData = BusinessData;
	CurrentRevenuePerSecond = BusinessData->BaseRevenuePerSecond;
	HeatGeneration = BusinessData->BaseHeatGeneration;

	UE_LOG(LogTemp, Warning, TEXT("Business started: %s | Revenue/sec: %.2f"), *BusinessData->BusinessName, CurrentRevenuePerSecond);
}

void UBusinessComponent::HireStaff(int32 Amount)
{
	if (!CurrentBusinessData) return;
	CurrentStaff = FMath::Clamp(CurrentStaff + Amount, 0, CurrentBusinessData->MaxStaff);
	CurrentRevenuePerSecond = CurrentBusinessData->BaseRevenuePerSecond * (1.0f + (CurrentStaff * 0.1f));

	UE_LOG(LogTemp, Warning, TEXT("Hired %d staff. Total: %d"), Amount, CurrentStaff);
}

void UBusinessComponent::UpgradeBusiness(int32 Level)
{
	UpgradeLevel += Level;
	CurrentRevenuePerSecond *= (1.0f + (Level * 0.25f));
	UE_LOG(LogTemp, Warning, TEXT("Business upgraded to Level %d"), UpgradeLevel);
}

float UBusinessComponent::GetCurrentRevenue() const
{
	return AccumulatedRevenue;
}

void UBusinessComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentBusinessData)
	{
		float DeltaRevenue = CurrentRevenuePerSecond * DeltaTime;
		AccumulatedRevenue += DeltaRevenue;

		// Simulate maintenance cost
		float Maintenance = CurrentBusinessData->BaseMaintenanceCostPerSecond * DeltaTime;
		AccumulatedRevenue -= Maintenance;
	}
}