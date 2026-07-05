#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "EmpireSaveGame.generated.h"

UCLASS()
class EMPIREANDBADGE_API UEmpireSaveGame : public USaveGame
{
    GENERATED_BODY()

public:
    UPROPERTY(VisibleAnywhere)
    float TotalMoney;

    UPROPERTY(VisibleAnywhere)
    TArray<FString> OwnedBusinesses;

    UPROPERTY(VisibleAnywhere)
    int32 WantedLevel;

    UFUNCTION(BlueprintCallable)
    void SaveEmpireData();

    UFUNCTION(BlueprintCallable)
    static UEmpireSaveGame* LoadEmpireData();
};