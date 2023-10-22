// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BalloonSpawnerManager.h"
#include "FPSPlayerController.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "GoodBalloon.generated.h"

UCLASS()
class POPONEHUNDRED_API AGoodBalloon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoodBalloon();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* m_actorMesh = nullptr;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* m_actorCollision;

	UPROPERTY(EditAnywhere)
	USoundBase* m_burstSound = nullptr;
	
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY()
	ABalloonSpawnerManager* m_balloonSpawnerManager;

	UPROPERTY()
	APawn* m_fpsCharacter = nullptr;

	UPROPERTY(EditAnywhere)
	AFPSPlayerController* m_characterController = nullptr;

private:
	float m_health = 1.0f;
};
