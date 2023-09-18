// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PopOneHundredGameModeBase.generated.h"

UCLASS()
class POPONEHUNDRED_API APopOneHundredGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	APopOneHundredGameModeBase();
	
private:
	virtual void BeginPlay() override;
};
