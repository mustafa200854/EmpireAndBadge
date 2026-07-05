#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EmpireUIDashboard.generated.h"

UCLASS()
class EMPIREANDBADGE_API UEmpireUIDashboard : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateRevenueDisplay(float Revenue);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateWantedLevel(int32 Level);

    UFUNCTION(BlueprintCallable)
    void ShowBusinessOverview();
};