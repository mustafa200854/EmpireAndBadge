#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HeistMission.generated.h"

UENUM(BlueprintType)
enum class EHeistObjective : uint8
{
    StealMoney,
    StealArtifact,
    Assassination,
    DestroyEvidence
};

UCLASS(BlueprintType)
class EMPIREANDBADGE_API UHeistMission : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void StartHeist(FString MissionName);

    UFUNCTION(BlueprintCallable)
    void CompleteObjective(EHeistObjective Objective);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<EHeistObjective> RequiredObjectives;

    UPROPERTY(BlueprintReadOnly)
    bool bIsActive;

private:
    int32 CompletedObjectives;
};