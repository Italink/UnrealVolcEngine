using System.IO;
using UnrealBuildTool;

public class UnrealVolcEngineRuntime: ModuleRules
{
	public UnrealVolcEngineRuntime(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        AddEngineThirdPartyPrivateStaticDependencies(Target, "zlib");

        PublicIncludePaths.AddRange(
			new string[] { 
            }
		);

        string EnginePath = Path.GetFullPath(Target.RelativeEnginePath);
        PrivateIncludePaths.AddRange(new string[]  {
            Path.Combine(EnginePath, "Plugins/FX/Niagara/Source/Niagara/Private")
        });

        PublicDependencyModuleNames.AddRange(
			new string[]
			{ 
                "Core",
                "RenderCore",
                "Engine",
                "RHI",
				"InputCore",
            }
            );
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
                "Projects",
				"Slate",
                "SlateCore",
                "Niagara",
                "NiagaraShader",
                "zlib",
                "Json",
                "HTTP",
                "WebSockets",
                "AudioMixer",
                "AudioCaptureCore"
            }
            );
    }
}
