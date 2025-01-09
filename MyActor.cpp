// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	start = FVector2D(0, 0);
	evCnt = 0;
	totDist = 0.0f;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	move();
	UE_LOG(LogTemp, Warning, TEXT("Total Distance : %d"), totDist);
	UE_LOG(LogTemp, Warning, TEXT("Total Event : %d"), evCnt);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

void AMyActor::move()
{
	FVector2D Position = start;
	
	UE_LOG(LogTemp, Warning, TEXT("Start Position : (%d, %d)"), (int)Position.X, (int)Position.Y);

	
	for (int i = 0; i < 10; i++)
	{
		FVector2D ABC = Position;
		int StepX = step();
		int StepY = step();

		Position += FVector2D(StepX, StepY);

		float Dist = distance(ABC, Position);
		totDist += Dist;

		UE_LOG(LogTemp, Warning, TEXT("Step %d : Position (%d, %d), Step Distance: %.2f"), i + 1, (int)Position.X, (int)Position.Y, Dist);
	}
	createEvent();
	UE_LOG(LogTemp, Warning, TEXT("Final Position : (%d, %d)"), (int)Position.X, (int)Position.Y);
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	return FVector2D::Distance(first, second);
}

int32 AMyActor::createEvent()
{
	int32 Event0 = FMath::RandRange(0, 1) == 1;
	if (Event0 == 1)
	{
		evCnt++;
		UE_LOG(LogTemp, Warning, TEXT("Event Count: %d"), evCnt);
	}
	return Event0;
}

