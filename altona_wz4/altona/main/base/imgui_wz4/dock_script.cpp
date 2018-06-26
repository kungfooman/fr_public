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


#include "../imgui/imgui_api.h"
extern sGui_ *sGui;


DockScript::DockScript() {}


const char *DockScript::label() {
	return "Script";
}

class TestMessage : public sObject { public:
	void bla() {
		imgui_log("blaaaa");
	}
};

TestMessage *testMessage = NULL;

void imgui_draw_wz_rect(sRect &rect, unsigned int color) {
	float left = rect.x0;
	float top = rect.y0;
	float right = rect.x1;
	float bottom = rect.y1;

	ImVec2 a;
	ImVec2 b;

	// from top/left to bottom/right
	a = ImVec2(left, top);
	b = ImVec2(bottom, right);
	//imgui_line(&a, &b, color, 1);
	

	a = ImVec2(left, top);
	b = ImVec2(right, top);
	imgui_line(&a, &b, color, 1);

	
	a = ImVec2(left, bottom);
	b = ImVec2(right, bottom);
	imgui_line(&a, &b, color, 1);

	
	a = ImVec2(left, top);
	b = ImVec2(left, bottom);
	imgui_line(&a, &b, color, 1);

	a = ImVec2(right, top);
	b = ImVec2(right, bottom);
	imgui_line(&a, &b, color, 1);

}

int depth = 0;
void dumpWindows(sWindow *window) {
	sWindow *subwindow;
	//if(w->Flags & sWF_BEFOREPAINT)
	//w->OnBeforePaint();

	sFORALL(window->Childs, subwindow)
	{
		ImGui::PushID(subwindow);
		ImGui::Text("Got Window depth=%d: %s %d %d %d %d", depth, subwindow->ToolTip,
			subwindow->Outer.x0, 
			subwindow->Outer.y0, 
			subwindow->Outer.x1, 
			subwindow->Outer.y1
		);
		


		
		imgui_draw_wz_rect(subwindow->Outer, 0xff00ffff);
		imgui_draw_wz_rect(subwindow->Inner, 0xff0000ff);


		
			if (ImGui::Button("bla")) {
				subwindow->AddButton(L"bla",sMessage(testMessage,&TestMessage::bla));
			}

			ImGui::PopID();
		depth++;
		dumpWindows(subwindow);
		depth--;
	}
}

void DockScript::imgui() {
	depth = 0;
	ImGui::Text("Root=%p", sGui->Root);
	

	dumpWindows(sGui->Root);

}