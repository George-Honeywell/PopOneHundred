// Fill out your copyright notice in the Description page of Project Settings.


#include "BalloonSpawnerManager.h"
#include "BalloonSpawner.h"
#include "Logging/StructuredLog.h"

// Sets default values
ABalloonSpawnerManager::ABalloonSpawnerManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABalloonSpawnerManager::BeginPlay()
{
	Super::BeginPlay();



	//const FVector spawnLoc = FVector(715.f, -1.0f, 250.0f);
	//const FVector spawnLoc = GetActorLocation();
	const FRotator spawnRot = GetActorRotation();	
	
	//m_balloonSpawner = GetWorld()->SpawnActor<ABalloonSpawner>(m_balloonSpawnerClass, spawnLoc, spawnRot, spawnParams);

	for(int i = 0; i < 10; i++)
	{
		// FActorSpawnParameters spawnParams = FActorSpawnParameters();
		// spawnParams.Owner = this;
		// spawnParams.Name = TEXT("BalloonSpawner");
		for(int j = 0; j < 10; j++)
		{
			const FVector spawnLoc = FVector(xPos, yPos, zPos);
			AActor* spawnersToAdd = Cast<ABalloonSpawner>(m_balloonSpawnerClass);
			m_arrBalloonSpawners.Add(spawnersToAdd);
			m_numOfGoodBalloons++;

			m_arrBalloonSpawners[i] = GetWorld()->SpawnActor<ABalloonSpawner>(m_balloonSpawnerClass, spawnLoc, spawnRot);
			zPos -= offsetZPos;
		}
		yPos += offsetYPos;
		zPos = 1200;
	}
}

// Called every frame
void ABalloonSpawnerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

