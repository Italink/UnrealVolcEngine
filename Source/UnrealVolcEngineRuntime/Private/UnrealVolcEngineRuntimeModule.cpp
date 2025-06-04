#include "UnrealVolcEngineRuntimeModule.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "UnrealVolcEngine"

void FUnrealVolcEngineRuntimeModule::StartupModule()
{
}

void FUnrealVolcEngineRuntimeModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FUnrealVolcEngineRuntimeModule, UnrealVolcEngineRuntime)