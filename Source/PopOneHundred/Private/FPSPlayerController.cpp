// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSPlayerController.h"

#include "Blueprint/UserWidget.h"

void AFPSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	m_worldRef = GetWorld();
	m_fpsCharacter = Cast<AFPSCharacter>(m_worldRef->GetFirstPlayerController()->GetCharacter());

	if(UUserWidget* aimDot = CreateWidget(this, m_aimDot))
		aimDot->AddToViewport();

	if(UUserWidget* scoreBoard = CreateWidget(this, m_scoreBoard))
		scoreBoard->AddToViewport();
}
