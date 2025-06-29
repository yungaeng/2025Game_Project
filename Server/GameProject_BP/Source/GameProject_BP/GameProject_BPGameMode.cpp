// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameProject_BPGameMode.h"
#include "GameProject_BPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameProject_BPGameMode::AGameProject_BPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
