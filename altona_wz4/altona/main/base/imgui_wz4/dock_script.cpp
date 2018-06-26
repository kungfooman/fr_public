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

size_t to_narrow(const wchar_t * src, char * dest, size_t dest_len){
  size_t i;
  wchar_t code;

  i = 0;

  while (src[i] != '\0' && i < (dest_len - 1)){
    code = src[i];
    if (code < 128)
      dest[i] = char(code);
    else{
      dest[i] = '?';
      if (code >= 0xD800 && code <= 0xD8FF)
        // lead surrogate, skip the next code unit, which is the trail
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
		
		// dynamic_cast throws an error, probably because of the custom new/delete
		//sGridFrame *gridFrame = dynamic_cast<sGridFrame *>(subwindow);
		if (strcmp(classname, "sGridFrame") == 0) {
		//if (gridFrame) {
			sGridFrame *gridFrame = (sGridFrame *)subwindow;
			sGridFrameLayout *gridFrameLayout = NULL;
			sFORALL(gridFrame->Layout, gridFrameLayout)
			{
				imgui_draw_wz_rect(gridFrameLayout->GridRect, 0x0000ffff);
			}

			
		}
		
		if (strcmp(classname, "WinStack") == 0) {
			
				auto winpos = ImGui::GetWindowPos();
				ImDrawList *drawList = ImGui::GetWindowDrawList();

				
				const float left   = subwindow->Inner.x0;
				const float top    = subwindow->Inner.y0;
				const float right  = subwindow->Inner.x1;
				const float bottom = subwindow->Inner.y1;

				drawList->AddRectFilled(
					winpos + ImVec2(left , top   ),
					winpos + ImVec2(right, bottom),
					0xFFcdc8c0
				);

			



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
				drawList->AddRectFilled(
					winpos + ImVec2(left , top   ),
					winpos + ImVec2(right, bottom),
					Color_WZ4_to_ImGui(stackOp->Class->OutputType->Color)
					//ImColor(stackOp->Class->OutputType->Color)
					//0xffff0000
				);

				const sChar *opName = winStack->MakeOpName(stackOp);
				char opNameChar[256];
				to_narrow(opName, opNameChar, sizeof(opNameChar));
				ImVec2 textpos = ImVec2(oprect.CenterX(), top - 1); // y0 is top
				textpos.x -= strlen(opNameChar) * 3; // one char is 6px, so go back 3px for each char, to center the string
				ImGui::SetCursorPos(textpos);
				ImGui::TextColored(ImColor(0xff000000), "%s", opNameChar);
				
				drawList->AddLine( // right gray line
					winpos + ImVec2(right - 1, top),
					winpos + ImVec2(right - 1, bottom),
					0xff808080
				);
				drawList->AddLine( // bottom gray line
					winpos + ImVec2(left,  bottom - 1),
					winpos + ImVec2(right, bottom - 1),
					0xff808080
				);
				drawList->AddLine( // left white line
					winpos + ImVec2(left, top   ),
					winpos + ImVec2(left, bottom),
					0xffffffff
				);
				drawList->AddLine( // top white line
					winpos + ImVec2(left , top),
					winpos + ImVec2(right, top),
					0xffffffff
				);

				
			}

			//page->
		}
			//sLayoutFrame
		ImGui::Text("Got %s depth=%d: %s %d %d %d %d",
			classname,
			depth, subwindow->ToolTip,
			subwindow->Outer.x0, 
			subwindow->Outer.y0, 
			subwindow->Outer.x1, 
			subwindow->Outer.y1
		);
		

		//
		
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