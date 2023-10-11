// Fill out your copyright notice in the Description page of Project Settings.


#include "BalloonSpawner.h"

#include "Components/GameStateComponent.h"
#include "Logging/StructuredLog.h"

ABalloonSpawner::ABalloonSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	m_boxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	RootComponent = m_boxComponent;
	
}

// Called when the game starts or when spawned
void ABalloonSpawner::BeginPlay()
{
	Super::BeginPlay();

	m_fpsCharacter = Cast<AFPSCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	
	const int rand = FMath::RandRange(1, 100);
	UE_LOGFMT(LogTemp, Log, "RandRange is {0}", rand);

	if(rand >= 10)
	{
		m_goodBalloon = GetWorld()->SpawnActor<AGoodBalloon>(m_goodBalloonClass);
		m_goodBalloon->AttachToComponent(m_boxComponent, FAttachmentTransformRules::KeepRelativeTransform);
		m_goodBalloon->SetOwner(this);
		m_fpsCharacter->m_numOfGoodBalloons++;
	}
	else
	{
		m_badBalloon = GetWorld()->SpawnActor<ABadBalloon>(m_badBalloonClass);
		m_badBalloon->AttachToComponent(m_boxComponent, FAttachmentTransformRules::KeepRelativeTransform);
		m_badBalloon->SetOwner(this);
		m_fpsCharacter->m_numOfBadBalloons++;
	}

	UE_LOGFMT(LogTemp, Display, "Number of Good Balloons:{0}", m_fpsCharacter->m_numOfGoodBalloons);
	UE_LOGFMT(LogTemp, Display, "Number of Bad Balloons:{0}", m_fpsCharacter->m_numOfBadBalloons);
}

// Called every frame
void ABalloonSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

