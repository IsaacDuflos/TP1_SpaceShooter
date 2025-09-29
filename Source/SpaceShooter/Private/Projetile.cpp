// Fill out your copyright notice in the Description page of Project Settings.


#include "Projetile.h"

// Sets default values
AProjetile::AProjetile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjetile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjetile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

