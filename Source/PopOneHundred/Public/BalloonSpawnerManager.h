// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BalloonSpawnerManager.generated.h"

class ABalloonSpawner;

UCLASS()
class POPONEHUNDRED_API ABalloonSpawnerManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABalloonSpawnerManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	int32 m_numOfGoodBalloons{0};

	UPROPERTY(BlueprintReadOnly)
	int32 m_numOfBadBalloons{0};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABalloonSpawner> m_balloonSpawnerClass;

	UPROPERTY()
	ABalloonSpawner* m_balloonSpawner;
	

private:
	UWorld* m_worldRef = nullptr;

};
