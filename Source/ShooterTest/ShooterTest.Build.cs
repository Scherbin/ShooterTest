// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShooterTest : ModuleRules
{
	public ShooterTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });

		PublicIncludePaths.AddRange(new string[] 
		{ 
			"ShooterTest/Public/Weapon",
			"ShooterTest/Public/UI",
			"ShooterTest/Public/Components"
		});
	}
}
