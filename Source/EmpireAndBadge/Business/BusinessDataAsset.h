#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BusinessDataAsset.generated.h"

UENUM(BlueprintType)
enum class EBusinessType : uint8
{
    Club UMETA(DisplayName = "Nightclub"),
    DrugLab UMETA(DisplayName = "Drug Laboratory"),
    Casino UMETA(DisplayName = "Casino"),
    StripClub UMETA(DisplayName = "Strip Club"),
    Garage UMETA(DisplayName = "Chop Shop")
};

UCLASS(BlueprintType)
class EMPIREANDBADGE_API UBusinessDataAsset : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Business")
    FString BusinessName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Business")
    EBusinessType BusinessType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy")
    float BaseRevenuePerSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy")
    float BaseMaintenanceCostPerSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Staff")
    int32 MaxStaff;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Risk")
    float BaseHeatGeneration; // 0.0 - 1.0
};