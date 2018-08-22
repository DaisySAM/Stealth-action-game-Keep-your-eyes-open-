#include "StealthGameAI.h"
#include "PickupActor.h"
#include "StealthGameAICharacter.h"

// Sets default values
APickupActor::APickupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
  
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneMesh"));
	RootComponent = SceneComp;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(SceneComp);

	RotationRate = FRotator(0.0f, 180.0f, 0.0f);
	Speed = 1.0f;

	//Box component
	BoxCollider= CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->bGenerateOverlapEvents = true;
	BoxCollider->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &APickupActor::OnBeginOverlap);
	BoxCollider->AttachTo(SceneComp);
}

void APickupActor::OnBeginOverlap(class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, 
	const FHitResult & SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)) {

		OnInteract();
	}
}

void APickupActor::OnInteract()
{
	FString StLog = FString::Printf(TEXT("Вы подобрали: %s\n"), *Name);
	//GEngine->AddOnScreenDebugMessage(1, 5, FColor::White, StLog);
	//Destroy();

	AStealthGameAICharacter* player = Cast<AStealthGameAICharacter>(UGameplayStatics::GetPlayerCharacter(this,0));

	if (player) {

		Show(false); // hiding pick up actor

		player->AddToInventory(this); // add it to inventory of the player 
	}

	GEngine->AddOnScreenDebugMessage(1, 3, FColor::Blue, *StLog);
}

// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
	Super::BeginPlay();
}

void APickupActor::Show(bool visible)
{
	ECollisionEnabled::Type collision = visible ?
		ECollisionEnabled::QueryAndPhysics :
		ECollisionEnabled::NoCollision;

	this->SetActorTickEnabled(visible);

	this->MeshComp->SetVisibility(visible);
	this->MeshComp->SetCollisionEnabled(collision);

	this->BoxCollider->SetCollisionEnabled(collision);

}

// Called every frame
void APickupActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	this->AddActorLocalRotation(RotationRate*DeltaTime*Speed);
}

