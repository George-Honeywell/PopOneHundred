// Fill out your copyright notice in the Description page of Project Settings.


#include "BalloonSpawner.h"
#include "Kismet/GameplayStatics.h"

ABalloonSpawner::ABalloonSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	m_boxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	RootComponent = m_boxComponent;
	m_boxComponent->SetBoxExtent(FVector(10,10,10));
}

// Called when the game starts or when spawned
void ABalloonSpawner::BeginPlay()
{
	Super::BeginPlay();

	AActor* spawner = UGameplayStatics::GetActorOfClass(GetWorld(), ABalloonSpawnerManager::StaticClass());
	m_balloonSpawnerManager = Cast<ABalloonSpawnerManager>(spawner);

	const int rand = FMath::RandRange(1, 100);
	if(rand >= 10)
	{
		m_goodBalloon = GetWorld()->SpawnActor<AGoodBalloon>(m_goodBalloonClass);
		m_goodBalloon->AttachToComponent(m_boxComponent, FAttachmentTransformRules::KeepRelativeTransform);
		m_balloonSpawnerManager->m_numOfGoodBalloons++;
	}
	else
	{
		m_badBalloon = GetWorld()->SpawnActor<ABadBalloon>(m_badBalloonClass);
		m_badBalloon->AttachToComponent(m_boxComponent, FAttachmentTransformRules::KeepRelativeTransform);
		m_balloonSpawnerManager->m_numOfBadBalloons++;
	}
}

// Called every frame
void ABalloonSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

