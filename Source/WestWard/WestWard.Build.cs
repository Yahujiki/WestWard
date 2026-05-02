// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WestWard : ModuleRules
{
	public WestWard(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"WestWard",
			"WestWard/Variant_Platforming",
			"WestWard/Variant_Platforming/Animation",
			"WestWard/Variant_Combat",
			"WestWard/Variant_Combat/AI",
			"WestWard/Variant_Combat/Animation",
			"WestWard/Variant_Combat/Gameplay",
			"WestWard/Variant_Combat/Interfaces",
			"WestWard/Variant_Combat/UI",
			"WestWard/Variant_SideScrolling",
			"WestWard/Variant_SideScrolling/AI",
			"WestWard/Variant_SideScrolling/Gameplay",
			"WestWard/Variant_SideScrolling/Interfaces",
			"WestWard/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
