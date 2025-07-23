// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class GameProject_BP : ModuleRules
{
    public GameProject_BP(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core", "CoreUObject", "Engine", "InputCore",
            "AudioCapture", "AudioAnalyzer", "AudioMixer",
            "Sockets", "Networking", "OnlineSubsystemSteam", "OnlineSubsystem"
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            "AudioCapture", "AudioAnalyzer", "AudioMixer"
        });

        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(new string[] {
                "UMGEditor",
                "SequencerCore",
                "CurveEditor",
                "PropertyEditor",
                "EditorConfig",
                "UnrealEd"
            });
        }
    }
}
