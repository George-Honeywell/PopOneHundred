// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	UPROPERTY(EditAnywhere, Category = "Actor Defaults")
	UStaticMeshComponent* m_actorMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Actor Defaults")
	UBoxComponent* m_actorCollision;

	UPROPERTY(EditAnywhere, Category = Sounds)
	USoundBase* m_burstSound = nullptr;
	
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

private:
	float m_health = 1.0f;
	uint8 test{0};
};
