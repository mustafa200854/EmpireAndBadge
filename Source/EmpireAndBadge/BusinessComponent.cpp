#include "BusinessComponent.h"

void UBusinessComponent::StartClubBusiness(FString ClubName)
{
	// TODO: Implement revenue loop, staff management, police heat
	DailyRevenue = 5000.0f;
	UE_LOG(LogTemp, Warning, TEXT("Club %s started!"), *ClubName);
}