#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PoliceHeatComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EMPIREANDBADGE_API UPoliceHeatComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPoliceHeatComponent();

    UFUNCTION(BlueprintCallable)
    void AddHeat(float Amount);

    UFUNCTION(BlueprintCallable)
    void ReduceHeat(float Amount);

    UFUNCTION(BlueprintCallable)
    int32 GetWantedLevel() const;

    UFUNCTION(BlueprintCallable)
    void TriggerCorruptionEvent();

protected:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    UPROPERTY(EditAnywhere)
    float CurrentHeat;

    UPROPERTY(EditAnywhere)
    float HeatDecayRate;

    int32 WantedLevel;
};