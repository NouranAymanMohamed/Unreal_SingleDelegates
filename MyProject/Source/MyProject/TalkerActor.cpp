// Fill out your copyright notice in the Description page of Project Settings.


#include "TalkerActor.h"

// Sets default values
ATalkerActor::ATalkerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATalkerActor::BeginPlay()
{
	Super::BeginPlay();
	
	StartTalkerTimer();
}

// Called every frame
void ATalkerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATalkerActor::StartTalkerTimer()
{
	FTimerHandle Timer;

	GetWorldTimerManager().SetTimer(Timer, this, &ATalkerActor::Talk, 3);
}

void ATalkerActor::Talk()
{
	MessageDelegate.ExecuteIfBound("Message" + FString::FromInt(MessageNumber));

	MessageNumber++;

	StartTalkerTimer();
}

