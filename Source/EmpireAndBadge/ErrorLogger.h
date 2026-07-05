#pragma once

#include "CoreMinimal.h"
#include "ErrorLogger.generated.h"

UCLASS()
class EMPIREANDBADGE_API UErrorLogger : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Error Logging")
	static void LogError(const FString& Message, const FString& Context = TEXT(""));

	UFUNCTION(BlueprintCallable, Category = "Error Logging")
	static void LogWarning(const FString& Message, const FString& Context = TEXT(""));

private:
	static void WriteToLogFile(const FString& LogType, const FString& Message, const FString& Context);
};