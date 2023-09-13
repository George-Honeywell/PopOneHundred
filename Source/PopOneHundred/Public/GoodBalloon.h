// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	//UPROPERTY(VisibleAnywhere, Category = "Actor Defaults")
	//USceneComponent* RootComponent;

	UPROPERTY(EditAnywhere, Category = "Actor Defaults")
	UStaticMeshComponent* m_actorMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Actor Defaults")
	UBoxComponent* m_actorCollision;
};
