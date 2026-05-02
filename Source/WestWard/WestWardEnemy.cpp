#include "WestWardEnemy.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

AWestWardEnemy::AWestWardEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add(FName("Enemy")); // Auto-tag as Enemy
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
}

void AWestWardEnemy::BeginPlay()
{
	Super::BeginPlay();
	PlayerActor = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}

void AWestWardEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!PlayerActor) return;
	float Dist = FVector::Dist(GetActorLocation(), PlayerActor->GetActorLocation());
	if (Dist <= DetectionRange)
	{
		FVector Dir = (PlayerActor->GetActorLocation() - GetActorLocation()).GetSafeNormal();
		AddMovementInput(Dir, 1.0f);
		FRotator LookAt = Dir.Rotation();
		LookAt.Pitch = 0.f; LookAt.Roll = 0.f;
		SetActorRotation(LookAt);
	}
}