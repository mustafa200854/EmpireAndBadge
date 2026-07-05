#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "OpenWorldStreaming.generated.h"

UCLASS()
class EMPIREANDBADGE_API UOpenWorldStreaming : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void StreamCitySection(FVector PlayerLocation);

    UFUNCTION(BlueprintCallable)
    void LoadHighDetailDistrict(FString DistrictName);
private:
    TMap<FString, bool> LoadedDistricts;
};