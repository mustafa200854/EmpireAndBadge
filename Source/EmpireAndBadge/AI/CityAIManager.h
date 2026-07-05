#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CityAIManager.generated.h"

UCLASS()
class EMPIREANDBADGE_API UCityAIManager : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    UFUNCTION(BlueprintCallable)
    void SpawnDynamicNPC(FVector Location);

    UFUNCTION(BlueprintCallable)
    void TriggerCityEvent();

private:
    int32 ActiveNPCs;
    TArray<FString> CityEvents;
};