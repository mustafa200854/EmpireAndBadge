#include "EmpirePlayerCharacter.h"

void AEmpirePlayerCharacter::SwitchToCopMode()
{
	UE_LOG(LogTemp, Warning, TEXT("Switched to Cop Mode - Corruption enabled"));
}

void AEmpirePlayerCharacter::SwitchToCriminalMode()
{
	UE_LOG(LogTemp, Warning, TEXT("Switched to Criminal Mode - Empire building enabled"));
}