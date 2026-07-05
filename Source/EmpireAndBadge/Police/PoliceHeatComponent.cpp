#include "PoliceHeatComponent.h"

UPoliceHeatComponent::UPoliceHeatComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    CurrentHeat = 0.0f;
    HeatDecayRate = 5.0f;
    WantedLevel = 0;
}

void UPoliceHeatComponent::AddHeat(float Amount)
{
    CurrentHeat += Amount;
    UpdateWantedLevel();
    UE_LOG(LogTemp, Warning, TEXT("Heat increased by %.1f | Current Heat: %.1f"), Amount, CurrentHeat);
}

void UPoliceHeatComponent::ReduceHeat(float Amount)
{
    CurrentHeat = FMath::Max(0.0f, CurrentHeat - Amount);
    UpdateWantedLevel();
}

int32 UPoliceHeatComponent::GetWantedLevel() const
{
    return WantedLevel;
}

void UPoliceHeatComponent::UpdateWantedLevel()
{
    WantedLevel = FMath::Clamp(FMath::FloorToInt(CurrentHeat / 25.0f), 0, 5);
}

void UPoliceHeatComponent::TriggerCorruptionEvent()
{
    if (WantedLevel > 2)
    {
        CurrentHeat *= 0.6f;
        UE_LOG(LogTemp, Warning, TEXT("Corruption activated - Heat reduced!"));
    }
}

void UPoliceHeatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    ReduceHeat(HeatDecayRate * DeltaTime);
}