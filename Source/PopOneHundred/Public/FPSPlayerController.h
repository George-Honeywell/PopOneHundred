// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSCharacter.h"
#include "GameFramework/PlayerController.h"
#include "FPSPlayerController.generated.h"

UCLASS()
class POPONEHUNDRED_API AFPSPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

	AFPSCharacter* m_fpsCharacter = nullptr;

	UWorld* m_worldRef = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerHUD)
		TSubclassOf<class UUserWidget> m_aimDot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerHUD)
		TSubclassOf<class UUserWidget> m_scoreBoard;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerHUD)
		TSubclassOf<class UUserWidget> m_gameOver;

	UFUNCTION()
	virtual void GameHasEnded(AActor* EndGameFocus, bool bIsWinner) override;

public:
	UPROPERTY(BlueprintReadOnly)
	int32 m_numOfBalloonsPopped{0};
};
