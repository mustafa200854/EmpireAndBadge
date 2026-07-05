#include "BusinessComponent.h"

void UBusinessComponent::InitializeBusiness(EBusinessType Type, FString Name)
{
	BusinessType = Type;
	BusinessName = Name;
	StaffCount = 10;

	switch(Type)
	{
		case EBusinessType::StripClub: DailyRevenue = 8500.0f; break;
		case EBusinessType::Bordell: DailyRevenue = 12500.0f; break;
		case EBusinessType::Nightclub: DailyRevenue = 18000.0f; break;
	}

	UE_LOG(LogTemp, Warning, TEXT("Business %s initialized! Daily Revenue: %f"), *Name, DailyRevenue);
}

void UBusinessComponent::TickRevenue(float DeltaTime)
{
	// Revenue + random events (raids, VIPs, etc.)
}

float UBusinessComponent::GetDailyRevenue() const
{
	return DailyRevenue;
}