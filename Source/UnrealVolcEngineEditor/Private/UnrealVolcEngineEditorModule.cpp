#include "UnrealVolcEngineEditorModule.h"
#include "EditorModeRegistry.h"
#include "UnrealVolcEngineSettings.h"
#include "ISettingsModule.h"
#include "WorkspaceMenuStructure.h"
#include "WorkspaceMenuStructureModule.h"
#include "SUnrealVolcEngineDebugTool.h"

#define LOCTEXT_NAMESPACE "UnrealVolcEngine"

void FUnrealVolcEngineEditorModule::StartupModule()
{
	UUnrealVolcEngineSettings* Settings = GetMutableDefault<UUnrealVolcEngineSettings>();
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule) {
		SettingsModule->RegisterSettings("Project", TEXT("Project"), TEXT("UnrealVolcEngine"),
			LOCTEXT("UnrealVolcEngine", "UnrealVolcEngine"),
			LOCTEXT("UnrealVolcEngine", "UnrealVolcEngine"),
			Settings);
	}
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
		"UnrealVolcEngine",
		FOnSpawnTab::CreateStatic(&FUnrealVolcEngineEditorModule::SpawnUnrealVolcEngineTab))
		.SetDisplayName(NSLOCTEXT("UnrealEditor", "UnrealVolcEngineTab", "Unreal Volc Engine"))
		.SetTooltipText(NSLOCTEXT("UnrealEditor", "UnrealVolcEngineTooltipText", "Open the Unreal Volc Engine Tab."))
		.SetGroup(WorkspaceMenu::GetMenuStructure().GetDeveloperToolsDebugCategory())
		.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "Debug"))
		.SetCanSidebarTab(false);
}

void FUnrealVolcEngineEditorModule::ShutdownModule()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule) {
		SettingsModule->UnregisterSettings("Project", TEXT("Project"), TEXT("UnrealVolcEngine"));
	}
	if (FSlateApplication::IsInitialized()){
		FGlobalTabmanager::Get()->UnregisterNomadTabSpawner("UnrealVolcEngine");
	}
}

void FUnrealVolcEngineEditorModule::RegisterMenus()
{
	
}

TSharedRef<class SDockTab> FUnrealVolcEngineEditorModule::SpawnUnrealVolcEngineTab(const FSpawnTabArgs& Args)
{
	auto NomadTab = SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		.Label(NSLOCTEXT("UnrealVolcEngine", "UnrealVolcEngineTabTitle", "Unreal Volc Engine"));

	auto TabManager = FGlobalTabmanager::Get()->NewTabManager(NomadTab);
	TabManager->SetOnPersistLayout(
		FTabManager::FOnPersistLayout::CreateStatic(
			[](const TSharedRef<FTabManager::FLayout>& InLayout)
			{
				if (InLayout->GetPrimaryArea().Pin().IsValid())
				{
					FLayoutSaveRestore::SaveToConfig(GEditorLayoutIni, InLayout);
				}
			}
		)
	);

	NomadTab->SetOnTabClosed(
		SDockTab::FOnTabClosedCallback::CreateStatic(
			[](TSharedRef<SDockTab> Self, TWeakPtr<FTabManager> TabManager)
			{
				TSharedPtr<FTabManager> OwningTabManager = TabManager.Pin();
				if (OwningTabManager.IsValid())
				{
					FLayoutSaveRestore::SaveToConfig(GEditorLayoutIni, OwningTabManager->PersistLayout());
					OwningTabManager->CloseAllAreas();
				}
			}
			, TWeakPtr<FTabManager>(TabManager)
		)
	);

	auto MainWidget = SNew(SUnrealVolcEngineDebugTool)
		.TabManager(TabManager);

	NomadTab->SetContent(MainWidget);
	return NomadTab;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FUnrealVolcEngineEditorModule, UnrealVolcEngineEditor)