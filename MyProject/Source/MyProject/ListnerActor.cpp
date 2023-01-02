// Fill out your copyright notice in the Description page of Project Settings.


#include "ListnerActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AListnerActor::AListnerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AListnerActor::BeginPlay()
{
	Super::BeginPlay();

	// Finding Actor with tag
	TArray<AActor*> TaggedActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Talker", TaggedActors);
		

	// Binding callback function to delegate
	if (TaggedActors.Num() > 0)
	{
		Talker = Cast<ATalkerActor>(TaggedActors[0]);			
		Talker->MessageDelegate.BindUObject(this, &AListnerActor::ReceiveMessage);
	}
	
}

// Called every frame
void AListnerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AListnerActor::ReceiveMessage(FString Message)
{
	UE_LOG(LogTemp, Warning, TEXT("Got Message: %s"), *Message);		
}

void AListnerActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	/*if (Talker != nullptr)
	{
		Talker->MessageDelegate.Unbind();
	}*/
}

