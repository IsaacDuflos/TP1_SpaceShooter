#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class SPACESHOOTER_API AProjectile : public AActor
{
	GENERATED_BODY()

public:	
	AProjectile();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	/** Mesh du projectile */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* ProjectileMesh;

	/** Mouvement du projectile */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement")
	class UProjectileMovementComponent* ProjectileMovement;

	/** Dégâts ou puissance (optionnel) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
	float Damage = 10.0f;
};
