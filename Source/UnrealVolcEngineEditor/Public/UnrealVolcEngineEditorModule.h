#pragma once

#include "Modules/ModuleManager.h"

class FUnrealVolcEngineEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
private:
	void RegisterMenus();
	static TSharedRef<class SDockTab> SpawnUnrealVolcEngineTab(const FSpawnTabArgs& Args);
};
