#include "../imgui/include_imgui.h"
#include "all_wz4.h"

// custom docks
#include "dock_angelscript.h"
#include "../imgui_docks/dock_console.h"
#include <portaudio.h>

DockAngelscript::DockAngelscript() {}

const char *DockAngelscript::label() {
	return "Angelscript";
}

void DockAngelscript::imgui() {
	ImGui::Text("asd");
	if (ImGui::Button("test some shit")) {
		
	}
}
