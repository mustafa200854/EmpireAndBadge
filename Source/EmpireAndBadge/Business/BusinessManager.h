#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "BusinessDataAsset.h"
#include "BusinessManager.generated.h"

UCLASS()
class EMPIREANDBADGE_API UBusinessManager : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    UFUNCTION(BlueprintCallable)
    void RegisterBusiness(AActor* Owner, UBusinessDataAsset* BusinessData);

    UFUNCTION(BlueprintCallable)
    void ProcessDailyRevenue();

    UFUNCTION(BlueprintCallable)
    TArray<FString> GetAllBusinessNames() const;

private:
    UPROPERTY()
    TArray<class UBusinessComponent*> ActiveBusinesses;

    float TotalDailyRevenue;
};