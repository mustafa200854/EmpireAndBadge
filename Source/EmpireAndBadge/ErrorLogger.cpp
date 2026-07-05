#include "ErrorLogger.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"

void UErrorLogger::LogError(const FString& Message, const FString& Context)
{
	WriteToLogFile(TEXT("ERROR"), Message, Context);
	UE_LOG(LogTemp, Error, TEXT("[ERROR] %s | %s"), *Message, *Context);
}

void UErrorLogger::LogWarning(const FString& Message, const FString& Context)
{
	WriteToLogFile(TEXT("WARNING"), Message, Context);
	UE_LOG(LogTemp, Warning, TEXT("[WARNING] %s | %s"), *Message, *Context);
}

void UErrorLogger::WriteToLogFile(const FString& LogType, const FString& Message, const FString& Context)
{
	FString LogEntry = FString::Printf(TEXT("[%s] %s - %s | %s\n"), *FDateTime::Now().ToString(), *LogType, *Message, *Context);
	FString LogFilePath = FPaths::ProjectSavedDir() + TEXT("EmpireErrorLog.txt");

	FFileHelper::SaveStringToFile(LogEntry, *LogFilePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FileAppend);
}