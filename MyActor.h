// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class ABC_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector2D start;
	int32 evCnt;
	int32 totDist;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float distance(FVector2D first, FVector2D second);
	int32 step();
	void move();
	int32 createEvent();
};
