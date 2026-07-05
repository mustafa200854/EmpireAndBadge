#include "EmpirePlayerCharacter.h"
#include "PoliceHeatComponent.h"
#include "BusinessComponent.h"
#include "Heist/HeistMission.h"

AEmpirePlayerCharacter::AEmpirePlayerCharacter()
{
    HeatComponent = CreateDefaultSubobject<UPoliceHeatComponent>(TEXT("HeatComponent"));
    BusinessComponent = CreateDefaultSubobject<UBusinessComponent>(TEXT("BusinessComponent"));
}

void AEmpirePlayerCharacter::SwitchToCopMode()
{
    UE_LOG(LogTemp, Warning, TEXT("Switched to Cop Mode - Corruption & Law Enforcement enabled"));
    if (HeatComponent) HeatComponent->ReduceHeat(100.0f);
}

void AEmpirePlayerCharacter::SwitchToCriminalMode()
{
    UE_LOG(LogTemp, Warning, TEXT("Switched to Criminal Mode - Empire Building & Heat Generation enabled"));
}

// New Heist Function
UFUNCTION(BlueprintCallable)
void AEmpirePlayerCharacter::StartHeistMission()
{
    UHeistMission* NewHeist = NewObject<UHeistMission>();
    if (NewHeist)
    {
        NewHeist->RequiredObjectives = { EHeistObjective::StealMoney, EHeistObjective::DestroyEvidence };
        NewHeist->StartHeist("Diamond Casino Heist");
        if (HeatComponent) HeatComponent->AddHeat(40.0f); // Heat from heist
    }
}