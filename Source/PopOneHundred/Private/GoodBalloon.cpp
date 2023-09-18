// Fill out your copyright notice in the Description page of Project Settings.


#include "GoodBalloon.h"

#include <ImportExport.h>

// Sets default values
AGoodBalloon::AGoodBalloon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	m_actorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Actor Mesh"));
	RootComponent = m_actorMesh;
	
	m_actorCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	m_actorCollision->SetupAttachment(m_actorMesh);
	m_actorCollision->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
}

// Called when the game starts or when spawned
void AGoodBalloon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGoodBalloon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

