#pragma once

#include "GameFramework/Character.h"
#include "EmpirePlayerCharacter.generated.h"

UCLASS()
class EMPIREANDBADGE_API AEmpirePlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AEmpirePlayerCharacter();

    UFUNCTION(BlueprintCallable)
    void SwitchToCopMode();

    UFUNCTION(BlueprintCallable)
    void SwitchToCriminalMode();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    class UPoliceHeatComponent* HeatComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    class UBusinessComponent* BusinessComponent;
};