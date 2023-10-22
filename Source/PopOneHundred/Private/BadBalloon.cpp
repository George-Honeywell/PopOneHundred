// Fill out your copyright notice in the Description page of Project Settings.


#include "BadBalloon.h"
#include "BalloonSpawnerManager.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

ABadBalloon::ABadBalloon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	m_actorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Actor Mesh"));
	RootComponent = m_actorMesh;
	
	m_actorCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	m_actorCollision->SetupAttachment(m_actorMesh);
	m_actorCollision->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));

	m_fpsCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void ABadBalloon::BeginPlay()
{
	Super::BeginPlay();
}

float ABadBalloon::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	AActor* spawner = UGameplayStatics::GetActorOfClass(GetWorld(), ABalloonSpawnerManager::StaticClass());
	m_balloonSpawnerManager = Cast<ABalloonSpawnerManager>(spawner);
	
	const float damageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	m_health -= damageToApply;

	if(m_burstSound)
		UGameplayStatics::PlaySoundAtLocation(this, m_burstSound, GetActorLocation());

	if(m_fpsCharacter->GetController())
		m_fpsCharacter->GetController()->GameHasEnded(m_fpsCharacter, false);
	
	m_balloonSpawnerManager->m_numOfBadBalloons--;
	
	Destroy();
	return damageToApply;
}