#pragma once

#include "GameFramework/Actor.h"
#include "PickupActor.generated.h"

UCLASS()
class STEALTHGAMEAI_API APickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void Show(bool visible);

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// MeshComponent
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PickUp)
	UStaticMeshComponent* MeshComp;

	// Rotator
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PickUp)
	FRotator RotationRate;

	//SceneComponent as Root
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PickUp)
	USceneComponent* SceneComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PickUp)
	float Speed;

	//UPROPERTY(VisibleAnywhere, Category = PickUp)
	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxCollider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PickUp)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PickUp)
	UTexture2D* Image;

	virtual void OnInteract();

	UFUNCTION()
	void OnBeginOverlap(class AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, 
		const FHitResult & SweepResult);
};
