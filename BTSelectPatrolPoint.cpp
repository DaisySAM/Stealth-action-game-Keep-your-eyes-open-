#include "StealthGameAI.h"
#include "BTSelectPatrolPoint.h"
#include "AIPatrolPoint.h"
#include "AIPatrolController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTSelectPatrolPoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAIPatrolController* AICon = Cast<AAIPatrolController>(OwnerComp.GetAIOwner());

	if (AICon) {
		/*Get BB component*/
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComp();

		AAIPatrolPoint* CurrentPoint = Cast<AAIPatrolPoint>(BlackboardComp->GetValueAsObject("LocationToGo"));
	
		TArray<AActor*> AvailablePatrolPoints = AICon->GetPatrolPoints();

		AAIPatrolPoint* NextPatrolPoint = nullptr;

		if (AICon->CurrentPatrolPoint != AvailablePatrolPoints.Num()-1) {

			NextPatrolPoint = Cast<AAIPatrolPoint>(AvailablePatrolPoints[++AICon->CurrentPatrolPoint]);

		}else //if there is not anymore points to go to
		{
			NextPatrolPoint = Cast<AAIPatrolPoint>(AvailablePatrolPoints[0]);
			AICon->CurrentPatrolPoint = 0;
		}

		BlackboardComp->SetValueAsObject("LocationToGo", NextPatrolPoint);

		return EBTNodeResult::Succeeded;
		
	}
	return EBTNodeResult::Failed;
}
