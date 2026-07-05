#include "EmpirePlayerCharacter.h"
#include "PoliceHeatComponent.h"
#include "BusinessComponent.h"

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