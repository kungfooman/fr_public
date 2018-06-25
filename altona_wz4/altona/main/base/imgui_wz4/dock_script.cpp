#include "../imgui/include_imgui.h"
#include "dock_script.h"
#include "../imgui_docks/dock_console.h"



DockScript::DockScript() {}


const char *DockScript::label() {
	return "Script";
}


void DockScript::imgui() {
	ImGui::Button("bla");

}