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
#include "gui/frames.hpp"
#include "wz4lib/gui.hpp"

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

// found on Stack Overflow, better than nothing, but fucks up צהü etc. into '?'
size_t to_narrow(const wchar_t * src, char * dest, size_t dest_len){
	size_t i;
	wchar_t code;
	i = 0;
	while (src[i] != '\0' && i < (dest_len - 1)) {
		code = src[i];
		if (code < 128) {
			dest[i] = char(code);
		} else {
			dest[i] = '?';
			if (code >= 0xD800 && code <= 0xD8FF) // lead surrogate, skip the next code unit, which is the trail
				i++;
		}
		i++;
	}
	dest[i] = '\0';
	return i - 1;
}

struct ColorWZ4 {
	unsigned char a;
	unsigned char b;
	unsigned char c; // blue
	unsigned char d;
};
struct ColorImGui {
	unsigned char a;
	unsigned char b;
	unsigned char c; // blue
	unsigned char d;
};

sU32 Color_WZ4_to_ImGui(sU32 col) {


	//ColorWZ4 *wz4 = (ColorWZ4 *)&col;
	//ColorImGui imgui = {0,0,0,0};
	
	unsigned char a = (col >> 24) & 0xff;
	unsigned char b = (col >> 16) & 0xff;
	unsigned char c = (col >>  8) & 0xff;
	unsigned char d = (col >>  0) & 0xff;

	unsigned int ret = 0;
	ret |= a << 24;
	ret |= d << 16;
	ret |= c <<  8;
	ret |= b <<  0;
	//return *(unsigned int *)&imgui;
	return ret;
}

// ideally i dont need to use ImGui::GetWindowPos() in "user code" at all, so abstract it away with some easy functions
// functions to bridge wz4<-->imgui drawing
void draw_rect(sRect rect, ImU32 color) {
	ImGuiWindow *window = ImGui::GetCurrentWindow();
	ImVec2 delta = window->Pos - window->Scroll;
	ImDrawList *drawList = ImGui::GetWindowDrawList();
	const float left   = delta.x + rect.x0;
	const float top    = delta.y + rect.y0;
	const float right  = delta.x + rect.x1;
	const float bottom = delta.y + rect.y1;
	drawList->AddRectFilled(ImVec2(left, top), ImVec2(right, bottom), color);
}
void draw_line(ImVec2 from, ImVec2 to, ImU32 color) {
	ImGuiWindow *window = ImGui::GetCurrentWindow();
	ImVec2 delta = window->Pos - window->Scroll;
	ImDrawList *drawList = ImGui::GetWindowDrawList();
	const float left   = delta.x + from.x;
	const float top    = delta.y + from.y;
	const float right  = delta.x + to.x;
	const float bottom = delta.y + to.y;
	drawList->AddLine(ImVec2(left, top), ImVec2(right, bottom), color);
}
void draw_outline(sRect rect, ImU32 color) {
	ImDrawList *drawList = ImGui::GetWindowDrawList();
	ImGuiWindow *window = ImGui::GetCurrentWindow();
	ImVec2 delta = window->Pos - window->Scroll;
	const float left   = delta.x + rect.x0;
	const float top    = delta.y + rect.y0;
	const float right  = delta.x + rect.x1;
	const float bottom = delta.y + rect.y1;
	drawList->AddRect(ImVec2(left, top), ImVec2(right, bottom), color);
}

// translate the absolute sRect wz4 position to the ImGui window position
ImRect translateImGui(sRect rect) {
	ImGuiWindow *window = ImGui::GetCurrentWindow();
	ImVec2 delta = window->Pos - window->Scroll;
	return ImRect(rect.x0 + delta.x, rect.y0 + delta.y, rect.x1 + delta.x, rect.y1 + delta.y);
}

int depth = 0;
void dumpWindows(sWindow *window) {
	sWindow *subwindow;
	//if(w->Flags & sWF_BEFOREPAINT)
	//w->OnBeforePaint();
	
	sFORALL(window->Childs, subwindow)
	{
		ImGui::PushID(subwindow);

		char classname[256];
		to_narrow(subwindow->GetClassName(), classname, sizeof(classname));
		//sWireMasterWindow



		
		ImDrawList *drawList = ImGui::GetWindowDrawList();

				
		const float left   = subwindow->Inner.x0;
		const float top    = subwindow->Inner.y0;
		const float right  = subwindow->Inner.x1;
		const float bottom = subwindow->Inner.y1;
		draw_rect(subwindow->Inner, 0xFFcdc8c0);

		draw_outline(subwindow->Outer, 0xff00ffff);
		draw_outline(subwindow->Inner, 0xff0000ff);

	
		ImGui::SetCursorPos(ImVec2(left, top));
		//if (ImGui::Button("Add Button")) {
		//	subwindow->AddButton(L"bla",sMessage(testMessage,&TestMessage::bla));
		//}


		// dynamic_cast throws an error, probably because of the custom new/delete
		//sGridFrame *gridFrame = dynamic_cast<sGridFrame *>(subwindow);
		if (strcmp(classname, "sGridFrame") == 0) {
		//if (gridFrame) {
			sGridFrame *gridFrame = (sGridFrame *)subwindow;
			sGridFrameLayout *gridFrameLayout = NULL;
			sFORALL(gridFrame->Layout, gridFrameLayout)
			{
				draw_outline(gridFrameLayout->GridRect, 0x0000ffff);
			}
		} else if (strcmp(classname, "sStringControl") == 0) {
		//if (gridFrame) {
			sStringControl *stringControl = (sStringControl *)subwindow;
			//sGridFrameLayout *gridFrameLayout = NULL;
			//sFORALL(gridFrame->Layout, gridFrameLayout)
			//{
			//	imgui_draw_wz_rect(gridFrameLayout->GridRect, 0x0000ffff);
			//}
			//stringControl->
			char charText[256];
			to_narrow(stringControl->GetText(), charText, sizeof(charText));
			
			ImGui::ItemAdd(translateImGui(subwindow->Inner), (ImGuiID)subwindow);
			//ImGui::ItemAdd(translateImGui(sRect(left, top, right, bottom)), (ImGuiID)subwindow);
			if (ImGui::IsItemHovered()) {
				ImGui::SetTooltip("Classname: %s", classname);
			}

			ImGui::Text("%s", charText);
		} else if (strcmp(classname, "WinStack") == 0) {
			WinStack *winStack = (WinStack *) subwindow;
			//printf("asd");
			/*
				sArray<wStackOp *> Ops;
				sArray<wTreeOp *> Tree;
			*/

			wPage *page = winStack->Page;

			wStackOp *stackOp;

			sFORALL(page->Ops, stackOp)
			{
				int scale_w = 24;
				int scale_h = 12;
				sRect oprect(
					subwindow->Inner.x0 + (stackOp->PosX * scale_w),
					subwindow->Inner.y0 + (stackOp->PosY * scale_h),
					subwindow->Inner.x0 + (stackOp->PosX * scale_w) + (stackOp->SizeX * scale_w),
					subwindow->Inner.y0 + (stackOp->PosY * scale_h) + (stackOp->SizeY * scale_h)
				);

				const float left   = oprect.x0;
				const float top    = oprect.y0;
				const float right  = oprect.x1;
				const float bottom = oprect.y1;

				//auto innerPlusOpRect = sRect(subwindow->Inner);
				//innerPlusOpRect.Add(oprect);
				//imgui_draw_wz_rect(oprect, 0xff00ffff);
				sRect rect = sRect(left, top, right, bottom);
				draw_rect(rect, Color_WZ4_to_ImGui(stackOp->Class->OutputType->Color));
				
				const sChar *opName = winStack->MakeOpName(stackOp);
				char opNameChar[256];
				to_narrow(opName, opNameChar, sizeof(opNameChar));
				ImVec2 textpos = ImVec2(oprect.CenterX(), top - 1); // y0 is top
				textpos.x -= strlen(opNameChar) * 3; // one char is 6px, so go back 3px for each char, to center the string
				ImGui::SetCursorPos(textpos);
				ImGui::TextColored(ImColor(0xff000000), "%s", opNameChar);
				
				draw_line( // right gray line
					ImVec2(right - 1, top),
					ImVec2(right - 1, bottom),
					0xff808080
				);
				draw_line( // bottom gray line
					ImVec2(left,  bottom - 1),
					ImVec2(right, bottom - 1),
					0xff808080
				);
				draw_line( // left white line
					ImVec2(left, top   ),
					ImVec2(left, bottom),
					0xffffffff
				);
				draw_line( // top white line
					ImVec2(left , top),
					ImVec2(right, top),
					0xffffffff
				);

				
			}

			//page->
		} else {
			// just print classname, when there is no case for the class
			ImGui::Text("%s", classname);
		}
			//sLayoutFrame
		//ImGui::Text("Got %s depth=%d: %s %d %d %d %d",
		//	classname,
		//	depth, subwindow->ToolTip,
		//	subwindow->Outer.x0, 
		//	subwindow->Outer.y0, 
		//	subwindow->Outer.x1, 
		//	subwindow->Outer.y1
		//);
		

		//
		


		

		ImGui::PopID();
		depth++;
		dumpWindows(subwindow);
		depth--;
	}

#if 0
	sFORALL(window->Borders, subwindow)
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
#endif
}

void DockScript::imgui() {
	depth = 0;
	ImGui::Text("Root=%p", sGui->Root);
	
	
	dumpWindows(sGui->Root);

}