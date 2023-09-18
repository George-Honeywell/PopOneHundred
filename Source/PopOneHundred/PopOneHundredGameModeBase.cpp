// Copyright Epic Games, Inc. All Rights Reserved.


#include "PopOneHundredGameModeBase.h"
#include "UObject/ConstructorHelpers.h"

APopOneHundredGameModeBase::APopOneHundredGameModeBase() : Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_FPSCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}

void APopOneHundredGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}


