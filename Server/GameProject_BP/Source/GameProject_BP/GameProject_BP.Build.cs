// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameProject_BP : ModuleRules
{
	public GameProject_BP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Sockets", "Networking", "OnlineSubsystemSteam", "OnlineSubsystem" });
	}
}
