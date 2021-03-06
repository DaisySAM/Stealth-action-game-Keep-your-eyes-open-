#include "StealthGameAI.h"
#include "StealthGameAIGameMode.h"
#include "StealthGameAICharacter.h"

AStealthGameAIGameMode::AStealthGameAIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
