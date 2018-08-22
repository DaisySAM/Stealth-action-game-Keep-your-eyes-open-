#include "StealthGameAI.h"
#include "AIPatrol.h"
#include "AIPatrolController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
AAIPatrol::AAIPatrol()
{
 	/*Initialize sensess*/
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(90.f);
}

// Called when the game starts or when spawned
void AAIPatrol::BeginPlay()
{
	Super::BeginPlay();
	
	if (PawnSensingComp) {
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AAIPatrol::OnPlayerCaught);
	}
}

// Called to bind functionality to input
void AAIPatrol::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

void AAIPatrol::OnPlayerCaught(APawn * Pawn)
{
	/*Get a reference to the player controller*/
	AAIPatrolController* AIController = Cast<AAIPatrolController>(GetController());

	if (AIController) {
		GEngine->AddOnScreenDebugMessage(-1, 0.2, FColor::Black, TEXT("За вами гонятся!"));
		AIController->SetPlayerCaught(Pawn);
	}
}

