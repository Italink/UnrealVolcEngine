#include "SUnrealVolcEngineDebugTool.h"
#include "UnrealVolcEngineSubsystem.h"

void SUnrealVolcEngineDebugTool::Construct(const FArguments& InArgs)
{
	TabManager = InArgs._TabManager;
	ChildSlot
		[
			SNew(SBorder)
			.OnMouseButtonDown(this, &SUnrealVolcEngineDebugTool::OnMicrophoneButtonDown)
			.OnMouseButtonUp(this, &SUnrealVolcEngineDebugTool::OnMicrophoneButtonUp)
			[
				SNew(STextBlock)
				.Text(FText::FromString("Micr"))
			]
		];
}

FReply SUnrealVolcEngineDebugTool::OnMicrophoneButtonDown(const FGeometry& Geometry, const FPointerEvent& Event)
{
	UUnrealVolcEngineSubsystem::Get()->StartListening(0);
	return FReply::Handled();
}

FReply SUnrealVolcEngineDebugTool::OnMicrophoneButtonUp(const FGeometry& Geometry, const FPointerEvent& Event)
{
	UUnrealVolcEngineSubsystem::Get()->StopListening();
	return FReply::Handled();
}

