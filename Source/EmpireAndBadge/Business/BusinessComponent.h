#pragma once

#include "CoreMinimal.h"
#include "BusinessComponent.generated.h"

UENUM(BlueprintType)
enum class EBusinessType : uint8
{
	StripClub,
	Bordell,
	Nightclub,
	Casino
};

UCLASS()
class EMPIREANDBADGE_API UBusinessComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Business")
	void InitializeBusiness(EBusinessType Type, FString Name);

	UFUNCTION(BlueprintCallable, Category = "Business")
	void TickRevenue(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Business")
	float GetDailyRevenue() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EBusinessType BusinessType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BusinessName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DailyRevenue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 StaffCount;
};