// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CapsuleComponent.h"
#include "Logging/StructuredLog.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(55.0f, 96.0f);

	m_cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_cameraComp->SetupAttachment(GetCapsuleComponent());
	m_cameraComp->SetRelativeLocation(FVector(-10.0f, 0.0f, 60.0f));
	m_cameraComp->bUsePawnControlRotation = true;

	m_shootFrom = CreateDefaultSubobject<USceneComponent>(TEXT("Shoot Point"));
	m_shootFrom->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));
	m_shootFrom->AttachToComponent(m_cameraComp, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();

	if(APlayerController* playerController = Cast<APlayerController>(Controller))
		if(UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
			subsystem->AddMappingContext(m_mappingContext, 0);
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(UEnhancedInputComponent* enhancedInputComp = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		enhancedInputComp->BindAction(m_look, ETriggerEvent::Triggered, this, &AFPSCharacter::Look);
		enhancedInputComp->BindAction(m_shoot, ETriggerEvent::Started, this, &AFPSCharacter::Shoot);
	}
}

void AFPSCharacter::Look(const FInputActionValue& value)
{
	FVector2D look = value.Get<FVector2D>();

	if(Controller)
	{
		AddControllerYawInput(look.X);
		AddControllerPitchInput(look.Y);
	}
}

void AFPSCharacter::Shoot()
{
	UE_LOG(LogTemp, Display, TEXT("Player Shot"));

	m_worldRef = GetWorld();

	//FVector location = GetActorLocation() + 50;
	FVector location = m_shootFrom->GetComponentLocation();
	FRotator rotation = GetControlRotation();
	FHitResult hitResult;
	FVector end = location + rotation.Vector() * distance;

	bool bIsHit = GetWorld()->LineTraceSingleByChannel(hitResult, location, end, ECC_GameTraceChannel1);

	if(bIsHit)
	{
		AActor* hitActor = hitResult.GetActor();
		FVector shotDirection = rotation.Vector();
		DrawDebugPoint(GetWorld(), hitResult.Location, 20, FColor::Green, false, 3.0f);
		DrawDebugLine(GetWorld(), location, hitResult.Location, FColor::Red, false, 3.0f, 0.0f, 2.0f);
		UE_LOGFMT(LogTemp, Log, "Hit {0}", *hitActor->GetName());
	}
}



