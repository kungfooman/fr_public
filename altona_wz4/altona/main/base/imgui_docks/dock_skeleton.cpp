#include "../imgui/include_imgui.h"
#include "dock_skeleton.h"

DockSkeleton::DockSkeleton() {
}

const char *DockSkeleton::label() {
	return "Skeleton";
}

void DockSkeleton::imgui() {
	ImGui::Button("DockSkeleton");
}