// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BadBalloon.h"
#include "GoodBalloon.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "PopOneHundred/PopOneHundredGameModeBase.h"
#include "BalloonSpawner.generated.h"

UCLASS()
class POPONEHUNDRED_API ABalloonSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABalloonSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGoodBalloon> m_goodBalloonClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABadBalloon> m_badBalloonClass;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* m_boxComponent;
	
	UPROPERTY()
	AGoodBalloon* m_goodBalloon;

	UPROPERTY()
	ABadBalloon* m_badBalloon;

	AFPSCharacter* m_fpsCharacter = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
