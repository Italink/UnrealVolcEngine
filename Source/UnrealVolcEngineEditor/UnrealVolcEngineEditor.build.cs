using UnrealBuildTool;
using System.IO;
public class UnrealVolcEngineEditor : ModuleRules
{
	public UnrealVolcEngineEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"UnrealEd", 
				"AssetTools",
				"Kismet",
				"Core",
				"RenderCore",
				"RHI",
				"AssetRegistry",
                "EditorFramework",
                "ImageCore",
                "Niagara",
                "UnrealVolcEngineRuntime",
            }
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore", 
				"Niagara",
                "MeshDescription",
                "StaticMeshDescription",
                "PropertyEditor",
                "UnrealEd",
                "AssetRegistry",
                "EditorStyle",
                "InputCore",
                "ContentBrowser",
                "ContentBrowserData",
                "ToolMenus",
                "Projects",
                "NiagaraEditor",
                "LevelEditor",
				"Json",
                "AssetTools",
				"Landscape",
                "AdvancedPreviewScene",
                "AssetDefinition",
                "JsonUtilities",
                "WorkspaceMenuStructure",
            }
		);
	}
}