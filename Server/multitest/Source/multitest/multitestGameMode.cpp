// Copyright Epic Games, Inc. All Rights Reserved.

#include "multitestGameMode.h"
#include "multitestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AmultitestGameMode::AmultitestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
