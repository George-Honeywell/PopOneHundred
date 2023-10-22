// Fill out your copyright notice in the Description page of Project Settings.


#include "BalloonSpawnerManager.h"
#include "BalloonSpawner.h"


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
	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			const FVector spawnLoc = FVector(xPos, yPos, zPos);
			const FRotator spawnRot = FRotator(0,0,0);
			AActor* spawnersToAdd = Cast<ABalloonSpawner>(m_balloonSpawnerClass); // TODO: Investigate this line of code, seems to take about a second to step over. Potential optimizations needed
			m_arrBalloonSpawners.Add(spawnersToAdd);

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

