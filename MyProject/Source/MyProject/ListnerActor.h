// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TalkerActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ListnerActor.generated.h"

UCLASS()
class MYPROJECT_API AListnerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AListnerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void ReceiveMessage(FString Message);

	/**
	 * Called when actor is being removed from level
	 * @param EndPlayReason why the actor is being removed
	*/
	UFUNCTION()
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	ATalkerActor* Talker;

};
