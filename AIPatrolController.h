#pragma once

#include "AIController.h"
#include "AIPatrolController.generated.h"

UCLASS()
class STEALTHGAMEAI_API AAIPatrolController : public AAIController
{
	GENERATED_BODY()

		/*Behavior tree component*/
		UBehaviorTreeComponent* BehaviorComp;
		/*Our blackboard component*/
		UBlackboardComponent* BlackboardComp;
		/*Blackboard keys*/
		UPROPERTY(EditDefaultsOnly, Category = AI)
			FName LocationToGoKey;

		UPROPERTY(EditDefaultsOnly, Category = AI)
			FName PlayerKey;

		TArray<AActor*> PatrolPoints;

		virtual void Possess(APawn* Pawn) override;

public:
	AAIPatrolController();

	void SetPlayerCaught(APawn* Pawn);

	int32 CurrentPatrolPoint = 0;

	/*Inline getter function*/
	
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
	FORCEINLINE TArray<AActor*> GetPatrolPoints() const { return PatrolPoints; }
};
