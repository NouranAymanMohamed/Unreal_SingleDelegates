// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TalkerActor.generated.h"

//Declaring the deledate.
DECLARE_DELEGATE_OneParam(FMessageDelegate, FString);

UCLASS()
class MYPROJECT_API ATalkerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATalkerActor();

	FMessageDelegate MessageDelegate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	int MessageNumber{1};

	//Starts talker timer, message is sent from talker to listener every 3 sec.
	void StartTalkerTimer();
	
	//Sends messages to listener.
	void Talk();
};
