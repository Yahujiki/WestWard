#include "WestWardCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "EngineUtils.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

AWestWardCharacter::AWestWardCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
    GetCharacterMovement()->JumpZVelocity = 700.f;
    GetCharacterMovement()->AirControl = 0.35f;
    GetCharacterMovement()->MaxWalkSpeed = 500.f;
    GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
    GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
    GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 400.0f;
    CameraBoom->bUsePawnControlRotation = true;
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;
}

void AWestWardCharacter::BeginPlay()
{
    Super::BeginPlay();

    // Add Input Mapping Contexts
    if (APlayerController* PC = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            for (UInputMappingContext* IMC : DefaultMappingContexts)
            {
                if (IMC) Subsystem->AddMappingContext(IMC, 0);
            }
        }
    }
}

void AWestWardCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (bIsDead) return;
    DamageTimer += DeltaTime;
    if (DamageTimer < 0.5f) return;
    DamageTimer = 0.0f;
    UWorld* World = GetWorld();
    if (!World) return;
    for (TActorIterator<AActor> It(World); It; ++It)
    {
        AActor* Actor = *It;
        if (!Actor) continue;
        if (Actor->ActorHasTag(FName("Enemy")))
        {
            float Dist = FVector::Dist(GetActorLocation(), Actor->GetActorLocation());
            if (Dist <= 300.0f)
            {
                ApplyDamage(5.0f);
                UE_LOG(LogTemp, Warning, TEXT("Health: %f"), Health);
                break;
            }
        }
    }
}

void AWestWardCharacter::ApplyDamage(float Amount)
{
    if (bIsDead) return;
    Health = FMath::Clamp(Health - Amount, 0.0f, MaxHealth);
    if (Health <= 0.0f)
    {
        bIsDead = true;
        // Show Game Over widget
        if (GameOverWidgetClass)
        {
            if (APlayerController* PC = Cast<APlayerController>(GetController()))
            {
                UUserWidget* GameOverWidget = CreateWidget<UUserWidget>(PC, GameOverWidgetClass);
                if (GameOverWidget)
                {
                    GameOverWidget->AddToViewport(10);
                    PC->bShowMouseCursor = true;
                    PC->SetInputMode(FInputModeUIOnly());
                }
            }
        }
    }
}

float AWestWardCharacter::GetHealthPercent() const
{
    if (MaxHealth <= 0.0f) return 0.0f;
    return Health / MaxHealth;
}

void AWestWardCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        if (MoveAction)
        {
            EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AWestWardCharacter::Move);
        }
        if (LookAction)
        {
            EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AWestWardCharacter::Look);
        }
        if (JumpAction)
        {
            EIC->BindAction(JumpAction, ETriggerEvent::Started,   this, &AWestWardCharacter::DoJumpStart);
            EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &AWestWardCharacter::DoJumpEnd);
        }
    }
}

void AWestWardCharacter::Move(const FInputActionValue& Value)
{
    FVector2D MoveVector = Value.Get<FVector2D>();
    DoMove(MoveVector.X, MoveVector.Y);
}

void AWestWardCharacter::Look(const FInputActionValue& Value)
{
    FVector2D LookVector = Value.Get<FVector2D>();
    DoLook(LookVector.X, LookVector.Y);
}

void AWestWardCharacter::DoMove(float Right, float Forward)
{
    if (Controller != nullptr)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector ForwardDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(ForwardDir, Forward);
        AddMovementInput(RightDir, Right);
    }
}
void AWestWardCharacter::DoLook(float Yaw, float Pitch) { AddControllerYawInput(Yaw); AddControllerPitchInput(Pitch); }
void AWestWardCharacter::DoJumpStart() { Jump(); }
void AWestWardCharacter::DoJumpEnd() { StopJumping(); }