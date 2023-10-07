// Fill out your copyright notice in the Description page of Project Settings.


#include "BalloonSpawner.h"

// Sets default values
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

	
	m_balloon = GetWorld()->SpawnActor<AGoodBalloon>(m_balloonClass);
	m_balloon->AttachToComponent(m_boxComponent, FAttachmentTransformRules::KeepRelativeTransform);
	m_balloon->SetOwner(this);
	
}

// Called every frame
void ABalloonSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

