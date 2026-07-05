#include "HeistMission.h"

void UHeistMission::StartHeist(FString MissionName)
{
    bIsActive = true;
    CompletedObjectives = 0;
    UE_LOG(LogTemp, Warning, TEXT("HEIST STARTED: %s"), *MissionName);
}

void UHeistMission::CompleteObjective(EHeistObjective Objective)
{
    if (!bIsActive) return;

    CompletedObjectives++;
    UE_LOG(LogTemp, Warning, TEXT("Objective completed! Progress: %d/%d"), CompletedObjectives, RequiredObjectives.Num());

    if (CompletedObjectives >= RequiredObjectives.Num())
    {
        UE_LOG(LogTemp, Warning, TEXT("HEIST SUCCESSFUL - Massive Payout!"));
        bIsActive = false;
    }
}