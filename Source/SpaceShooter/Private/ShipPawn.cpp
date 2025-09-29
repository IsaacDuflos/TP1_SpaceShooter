#include "ShipPawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/GameplayStatics.h"
#include "Projectile.h" // ton projectile à créer

AShipPawn::AShipPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMesh;
}

void AShipPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AShipPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShipPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &AShipPawn::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &AShipPawn::MoveUp);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AShipPawn::Fire);
}

void AShipPawn::MoveRight(float Value)
{
	if (Value != 0.f)
	{
		AddActorLocalOffset(FVector(Value * MoveSpeed * GetWorld()->GetDeltaSeconds(), 0, 0), true);
	}
}

void AShipPawn::MoveUp(float Value)
{
	if (Value != 0.f)
	{
		AddActorLocalOffset(FVector(0, Value * MoveSpeed * GetWorld()->GetDeltaSeconds(), 0), true);
	}
}

void AShipPawn::Fire()
{
	if (ProjectileClass)
	{
		APlayerController* PC = Cast<APlayerController>(GetController());
		if (PC)
		{
			FHitResult Hit;
			PC->GetHitResultUnderCursor(ECC_Visibility, false, Hit);

			if (Hit.bBlockingHit)
			{
				FVector ShipPos = GetActorLocation();
				FVector Target = Hit.Location;

				FVector Dir = Target - ShipPos;
				Dir.Z = 0; // on reste sur le plan X/Y
				Dir.Normalize();

				FVector SpawnLocation = ShipMesh->GetComponentLocation() + Dir * 100.f;
				FRotator SpawnRotation = Dir.Rotation();

				GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
			}
		}
	}
}