#include "CityAIManager.h"
#include "Kismet/GameplayStatics.h"

void UCityAIManager::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    ActiveNPCs = 0;
    CityEvents = { "Gang War", "Police Raid", "Black Market Deal", "Celebrity Party" };
}

void UCityAIManager::SpawnDynamicNPC(FVector Location)
{
    ActiveNPCs++;
    UE_LOG(LogTemp, Warning, TEXT("Spawned Dynamic NPC at location. Total NPCs: %d"), ActiveNPCs);
}

void UCityAIManager::TriggerCityEvent()
{
    if (CityEvents.Num() > 0)
    {
        FString Event = CityEvents[FMath::RandRange(0, CityEvents.Num() - 1)];
        UE_LOG(LogTemp, Warning, TEXT("CITY EVENT TRIGGERED: %s"), *Event);
        // Could affect Heat or Business Revenue
    }
}