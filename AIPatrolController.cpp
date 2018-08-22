#include "StealthGameAI.h"
#include "AIPatrolController.h"
#include "AIPatrol.h"
#include "AIPatrolPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"

void AAIPatrolController::Possess(APawn * Pawn)
{
	Super::Possess(Pawn);

	/*Get reference to the character*/
	AAIPatrol* AICharacter = Cast<AAIPatrol>(Pawn);

	if (AICharacter) {
		if (AICharacter->BehaviorTree->BlackboardAsset) {
			BlackboardComp->InitializeBlackboard(*(AICharacter->BehaviorTree->BlackboardAsset));
		}
    
		/*Populate patrol point array*/
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAIPatrolPoint::StaticClass(), PatrolPoints);
    
		BehaviorComp->StartTree(*AICharacter->BehaviorTree);
	}
}

AAIPatrolController::AAIPatrolController()
{
	/*Initialize blackboard and behavior tree*/
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	/*Initialize blackboard keys*/
	PlayerKey = "Target";
	LocationToGoKey = "LocationToGo";

	CurrentPatrolPoint = 0;
}

void AAIPatrolController::SetPlayerCaught(APawn * Pawn)
{
	if (BlackboardComp) {
		BlackboardComp->SetValueAsObject(PlayerKey, Pawn);
	}
}
