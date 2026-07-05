#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VehicleComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EMPIREANDBADGE_API UVehicleComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void EnterVehicle(AActor* Vehicle);

    UFUNCTION(BlueprintCallable)
    void Accelerate(float Value);

private:
    AActor* CurrentVehicle;
};