#pragma once

#include "GameFramework/Character.h"
#include "EmpirePlayerCharacter.generated.h"

UCLASS()
class EMPIREANDBADGE_API AEmpirePlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SwitchToCopMode();

	UFUNCTION(BlueprintCallable)
	void SwitchToCriminalMode();
};