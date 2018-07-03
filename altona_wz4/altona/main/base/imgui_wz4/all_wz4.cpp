#include "../imgui/include_imgui.h"
#include "all_wz4.h"

// custom docks
#include "dock_script.h"
#include "dock_portaudio.h"


#include <list>
std::list<Dock *> *imgui_wz4_docks = NULL;

void render_all_wz4_docks() {
	if (imgui_wz4_docks == NULL) {
		imgui_wz4_docks = new std::list<Dock *>();

		(*imgui_wz4_docks).push_back(new DockScript());
		(*imgui_wz4_docks).push_back(new DockPortaudio());
	}

	for (Dock *dock : *imgui_wz4_docks) {
		bool closed = true;
		if (BeginDock(dock->label(), &closed, 0, dock->cdock)) {
			//if (dock->cdock == NULL)
			//	dock->cdock = (CDock *)imgui_get_current_dock();

			//ImVec2 scrolling = ImVec2( ImGui::GetScrollX(), ImGui::GetScrollY() );
			//dock->screenpos = ImGui::GetCursorScreenPos() + scrolling;
			//dock->size = ImGui::GetWindowSize();
			dock->imgui();
		}
		EndDock();
	}
}