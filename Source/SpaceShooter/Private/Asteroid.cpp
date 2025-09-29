#include "Asteroid.h"
#include "Kismet/GameplayStatics.h"

AAsteroid::AAsteroid()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	// Autorise la collision
	Mesh->SetSimulatePhysics(false);
	Mesh->SetCollisionProfileName(TEXT("BlockAll"));
}

void AAsteroid::BeginPlay()
{
	Super::BeginPlay();

	// Vie aléatoire entre 1 et 3 tirs
	Health = FMath::RandRange(1, 3);

	// Direction aléatoire par défaut
	float X = FMath::FRandRange(-1.f, 1.f);
	float Y = FMath::FRandRange(-1.f, 1.f);
	MoveDirection = FVector(X, Y, 0).GetSafeNormal();
}

void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Déplacement
	FVector NewLocation = GetActorLocation() + MoveDirection * MoveSpeed * DeltaTime;
	SetActorLocation(NewLocation);
}

void AAsteroid::TakeDamageFromProjectile()
{
	Health--;

	if (Health <= 0)
	{
		// Ajoute ici un effet visuel d’explosion si tu veux
		Destroy();
	}
}
