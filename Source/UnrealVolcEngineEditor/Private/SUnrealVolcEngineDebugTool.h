#pragma once

#include "Widgets/SCompoundWidget.h"
#include "Widgets/Views/SListView.h"
#include "Widgets/Input/STextComboBox.h"
#include "Widgets/Layout/SWidgetSwitcher.h"

class SUnrealVolcEngineDebugTool: public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SUnrealVolcEngineDebugTool) {}
		SLATE_ARGUMENT(TSharedPtr<class FTabManager>, TabManager)
	SLATE_END_ARGS()
public:
	void Construct(const FArguments& InArgs);

	FReply OnMicrophoneButtonDown(const FGeometry& Geometry, const FPointerEvent& Event);

	FReply OnMicrophoneButtonUp(const FGeometry& Geometry, const FPointerEvent& Event);
protected:
	TSharedPtr<FTabManager>	TabManager;
};