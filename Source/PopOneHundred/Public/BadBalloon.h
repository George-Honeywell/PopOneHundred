// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BalloonSpawnerManager.h"
#include "Components/BoxComponent.h"
#include "BadBalloon.generated.h"

/**
 * 
 */
UCLASS()
class POPONEHUNDRED_API ABadBalloon : public AActor
{
	GENERATED_BODY()

protected:
	ABadBalloon();
	
	virtual void BeginPlay() override;
	
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	APawn* m_fpsCharacter = nullptr;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* m_actorMesh = nullptr;

	UPROPERTY()
	UBoxComponent* m_actorCollision = nullptr;
	
	UPROPERTY(EditAnywhere)
	USoundBase* m_burstSound = nullptr;
	
	UPROPERTY()
	ABalloonSpawnerManager* m_balloonSpawnerManager;

private:
	float m_health = 1.0f;
};
