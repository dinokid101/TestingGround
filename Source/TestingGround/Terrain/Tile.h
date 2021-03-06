// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

UCLASS()
class TESTINGGROUND_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

	UFUNCTION(BlueprintCallable, Category = "Actor")
		void PlaceActors(TSubclassOf<AActor> ToSpawn, int32 MinSpawn = 1, int32 MaxSpawn = 5, float Radius = 500);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool IsAbleToSpawnAtLocation(FVector Location, float Radius);
	bool FindEmptyLocation(FVector& OutLocation, float Radius);
	void PlaceActor(TSubclassOf<AActor> ToSpawn, FVector RandomPoint);
};
