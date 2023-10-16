// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BalloonSpawnerManager.generated.h"

class ABalloonSpawner;

UCLASS()
class POPONEHUNDRED_API ABalloonSpawnerManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABalloonSpawnerManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	int32 m_numOfGoodBalloons{0};

	UPROPERTY(BlueprintReadOnly)
	int32 m_numOfBadBalloons{0};

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABalloonSpawner> m_balloonSpawnerClass;

	UPROPERTY()
	ABalloonSpawner* m_balloonSpawner;

	UPROPERTY()
	TArray<AActor*> m_arrBalloonSpawners;

	// Default values for Spawners to spawn at
	UPROPERTY(EditAnywhere)
	double xPos = 0;

	UPROPERTY(EditAnywhere)
	double yPos = 0;

	UPROPERTY(EditAnywhere)
	double zPos = 0;

	// Offset the spawners to spawn in a grid
	UPROPERTY(EditAnywhere)
	double offsetXPos = 0;

	UPROPERTY(EditAnywhere)
	double offsetYPos = 0;

	UPROPERTY(EditAnywhere)
	double offsetZPos = 0;

	

};
