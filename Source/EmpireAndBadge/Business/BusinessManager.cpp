#include "BusinessManager.h"
#include "BusinessComponent.h"
#include "Kismet/GameplayStatics.h"

void UBusinessManager::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    TotalDailyRevenue = 0.0f;
}

void UBusinessManager::RegisterBusiness(AActor* Owner, UBusinessDataAsset* BusinessData)
{
    if (!Owner) return;

    UBusinessComponent* Component = Owner->FindComponentByClass<UBusinessComponent>();
    if (Component)
    {
        Component->StartBusiness(BusinessData);
        ActiveBusinesses.Add(Component);
        UE_LOG(LogTemp, Warning, TEXT("Business registered: %s"), *BusinessData->BusinessName);
    }
}

void UBusinessManager::ProcessDailyRevenue()
{
    TotalDailyRevenue = 0.0f;
    for (UBusinessComponent* Biz : ActiveBusinesses)
    {
        if (Biz)
        {
            TotalDailyRevenue += Biz->GetCurrentRevenue();
        }
    }
    UE_LOG(LogTemp, Warning, TEXT("Daily Empire Revenue: $%.2f"), TotalDailyRevenue);
}

TArray<FString> UBusinessManager::GetAllBusinessNames() const
{
    TArray<FString> Names;
    for (UBusinessComponent* Biz : ActiveBusinesses)
    {
        if (Biz && Biz->GetOwner())
            Names.Add(Biz->GetOwner()->GetName());
    }
    return Names;
}