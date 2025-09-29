#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Asteroid.generated.h"

UCLASS()
class SPACESHOOTER_API AAsteroid : public AActor
{
	GENERATED_BODY()

public:	
	AAsteroid();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// Mesh de l'astéroïde
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	// Vitesse de déplacement
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveSpeed = 200.f;

	// Direction de déplacement
	FVector MoveDirection;

	// Vie (nombre de tirs nécessaires)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Health;
    
	// Quand il est touché
	void TakeDamageFromProjectile();
};
