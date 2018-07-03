#include "../imgui/include_imgui.h"
#include "all_wz4.h"

// custom docks
#include "dock_portaudio.h"


DockPortaudio::DockPortaudio() {}

const char *DockPortaudio::label() {
	return "Portaudio";
}

void DockPortaudio::imgui() {
	//depth = 0;
	ImGui::Text("Root=%p", 321);



}