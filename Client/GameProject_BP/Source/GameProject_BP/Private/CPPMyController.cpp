#include "CPPMyController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/LocalPlayer.h"
#include "Blueprint/UserWidget.h"
#include "CPP_W_Indicator.h" 
#include "Kismet/GameplayStatics.h"

ACPPMyController::ACPPMyController()
{
    static ConstructorHelpers::FObjectFinder<UInputMappingContext> MappingContextObj(TEXT("/Game/MyAdventurer/IMC_Adventurer.IMC_Adventurer"));
    if (MappingContextObj.Succeeded())
    {
        DefaultMappingContext = MappingContextObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UInputAction> MoveActionObj(TEXT("/Game/MyImposter/IA_Move_I.IA_Move_I"));
    if (MoveActionObj.Succeeded())
    {
        MoveAction = MoveActionObj.Object;
    }

    static ConstructorHelpers::FObjectFinder<UInputAction> LookActionObj(TEXT("/Game/MyImposter/IA_Rotate_I.IA_Rotate_I"));
    if (LookActionObj.Succeeded())
    {
        LookAction = LookActionObj.Object;
    }
}

void ACPPMyController::BeginPlay()
{
    Super::BeginPlay();

    
    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (DefaultMappingContext)
            {
                Subsystem->AddMappingContext(DefaultMappingContext, 0);
            }
        }
    }

}

void ACPPMyController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
    {
        if (MoveAction)
        {
            EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPPMyController::Move);
        }
        if (LookAction)
        {
            EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPPMyController::Look);
        }
    }
}

void ACPPMyController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    ControlledPawn = InPawn;

    SpawnIndicators(); 
}

void ACPPMyController::SpawnIndicators()
{
    TArray<AActor*> TargetActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawn::StaticClass(), TargetActors);

    for (AActor* Actor : TargetActors)
    {
        if (Actor == ControlledPawn) continue; // 본인 제외

        // 위젯 생성
        if (BP_IndicatorWidgetClass)
        {
            UCPP_W_Indicator* Indicator = CreateWidget<UCPP_W_Indicator>(this, BP_IndicatorWidgetClass);
            if (Indicator)
            {
                Indicator->SetTarget(Actor); // 타겟 지정
                Indicator->AddToViewport();  // 뷰포트에 추가
                IndicatorWidgets.Add(Indicator);
            }
        }
    }
}

void ACPPMyController::Move(const FInputActionValue& Value)
{
    FVector2D MovementVector = Value.Get<FVector2D>();
    
    if (!ControlledPawn || MovementVector.IsNearlyZero())
        return;

    // 캐릭터가 바라보는 방향 기준 회전
    FRotator ControlRot = GetControlRotation();
    FRotator YawRotation(0, ControlRot.Yaw, 0);

    FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); // W/S
    FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);   // A/D

    // 올바른 방향으로 이동
    ControlledPawn->AddMovementInput(Forward, MovementVector.X);
    ControlledPawn->AddMovementInput(Right, MovementVector.Y);
}


void ACPPMyController::Look(const FInputActionValue& Value)
{
    FVector2D LookAxisVector = Value.Get<FVector2D>();
    AddYawInput(LookAxisVector.X);
    AddPitchInput(LookAxisVector.Y);
}