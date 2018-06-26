//#define sSTRIPPED 1

//#define __PLACEMENT_NEW_INLINE
//#define __PLACEMENT_VEC_NEW_INLINE
#include "../types.hpp"

#define DO_DONT_DEFINE_IMGUI_NEW 1

//#undef new
//#undef __PLACEMENT_NEW_INLINE
//#undef __PLACEMENT_VEC_NEW_INLINE

#if 0
//#undef new

//#define new sDEFINE_NEW
#define __PLACEMENT_NEW_INLINE
#define __PLACEMENT_VEC_NEW_INLINE


#undef new
#endif

#include "gui/manager.hpp"

#include "../imgui/include_imgui.h"
#include "dock_script.h"
#include "../imgui_docks/dock_console.h"



extern sGui_ *sGui;


DockScript::DockScript() {}


const char *DockScript::label() {
	return "Script";
}




void DockScript::imgui() {
	if (ImGui::Button("bla")) {

	}

	ImGui::Text("Root=%p", sGui->Root);

}