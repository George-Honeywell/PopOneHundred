// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AFPSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	m_worldRef = GetWorld();
	m_fpsCharacter = Cast<AFPSCharacter>(m_worldRef->GetFirstPlayerController()->GetCharacter());

	if(UUserWidget* aimDot = CreateWidget(this, m_aimDot))
		aimDot->AddToViewport();
}

void AFPSPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	if(UUserWidget* gameOver = CreateWidget(this, m_gameOver))
	{
		gameOver->AddToViewport();
		UGameplayStatics::SetGamePaused(GetWorld(), true);
		bShowMouseCursor = true;
		bEnableClickEvents = true;
		bEnableMouseOverEvents = true;
	}
}
