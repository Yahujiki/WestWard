#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WestWardEnemy.generated.h"

UCLASS()
class WESTWARD_API AWestWardEnemy : public ACharacter
{
    GENERATED_BODY()
public:
    AWestWardEnemy();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float DetectionRange = 500.0f;
protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
private:
    AActor* PlayerActor = nullptr;
};