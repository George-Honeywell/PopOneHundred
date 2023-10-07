// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GoodBalloon.h"
#include "GameFramework/Actor.h"
#include "BalloonSpawner.generated.h"

UCLASS()
class POPONEHUNDRED_API ABalloonSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABalloonSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGoodBalloon> m_balloonClass;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* m_boxComponent;
	
	UPROPERTY()
	AGoodBalloon* m_balloon;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
