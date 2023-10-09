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

	uint8 m_numOfGoodBalloons{0};
	uint8 m_numOfBadBalloons{0};
private:
	virtual void BeginPlay() override;
};
