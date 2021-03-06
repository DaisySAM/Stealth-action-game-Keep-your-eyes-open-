#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "BTSelectPatrolPoint.generated.h"

UCLASS()
class STEALTHGAMEAI_API UBTSelectPatrolPoint : public UBTTaskNode
{
	GENERATED_BODY()

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
