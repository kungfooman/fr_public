#include "include_imgui.h"
#include "imgui_dock.h"
#include "imgui_api.h"
#include "examples/imgui_impl_dx9.h"
#include "examples/imgui_impl_win32.h"
#include "imgui_default_docks.h"
#include "../imgui_wz4/all_wz4.h"


#undef new
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#define new sDEFINE_NEW

extern IDirect3DDevice9 *DXDev;

void alignTabsDefault() {
	for (CDock *dock : g_dock.m_docks) {
	//	g_dock.doUndock(*dock);
	//	dock->status = Status_Float;
		if (dock->label[0] == 0)
			continue; // dont try to undock ghost docks
		undock(dock);
	}

	//first = 0;
	//CDock *all = findDock("All");
	CDock *demostuff = findDock("DemoStuff");
	//CDock *tex = findDock("Textures");
	CDock *con = findDock("Console");
	CDock *node = findDock("Node");
	CDock *script = findDock("Script");

	//dockTop(demostuff, NULL);
	dockTop(demostuff, NULL);
	//
	dockBottom(con, demostuff);
	dockRight(node, con);
	//dockRight(script, con);
	//dockTab(tex, node);

	// dock all the rest to top
	for (CDock *dock : g_dock.m_docks) {
		//	strcpy(dock->location, "2"); // 1=left, 2=top, 3=bottom, 4=right
		//	dock->status = Status_::Status_Docked;
		//	g_dock.doDock(*dock, g_dock.getRootDock(), Slot_::Slot_Top);
		if (dock->status == Status_::Status_Docked)
			continue;

		dockTab(dock, demostuff);
	}
}

CCALL void imgui_line(ImVec2 *a, ImVec2 *b, unsigned int color, float thickness) {
	ImGuiWindow *window = ImGui::GetCurrentWindow();

	//ImVec2 winpos = ImGui::GetWindowPos();
	*a += window->Pos; // make the line relative to window and scroll position
	*b += window->Pos;
	*a -= window->Scroll;
	*b -= window->Scroll;

	window->DrawList->AddLine(*a, *b, color, thickness);
}

CCALL void imgui_point(ImVec2 *a, float radius, unsigned int color, int num_segments) {
	ImGuiWindow *window = ImGui::GetCurrentWindow();
	*a += window->Pos; // make the line relative to window and scroll position
	*a -= window->Scroll;
	window->DrawList->AddCircleFilled(*a, radius, color, num_segments);
}

static bool show_demo_window = true;
static bool show_another_window = false;
static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

void imgui_frame_start() {
			//// first make sure everything is undocked

		static int second = 0;
		if (second==3) {
			alignTabsDefault();
			second++;
		} else {
			if (second < 10)
				second++;
		}


    // Main loop
    //MSG msg;
    //ZeroMemory(&msg, sizeof(msg));
    //ShowWindow(sHWND, SW_SHOWDEFAULT);
    //UpdateWindow(hwnd);
    //while (msg.message != WM_QUIT)
    //{
        // Poll and handle messages (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        //if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        //{
        //    TranslateMessage(&msg);
        //    DispatchMessage(&msg);
        //    continue;
        //}

        // Start the ImGui frame
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

		ImGuiIO &io = ImGui::GetIO();
		ImGui::SetNextWindowPos( ImVec2(0,0) );
		ImGui::SetNextWindowSize(io.DisplaySize); // this used to work, but not in latest imgui version... need to call SetWindowSize() now
		ImGui::Begin("BCKGND", NULL, ImGui::GetIO().DisplaySize, 0.0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus);		
		//ImGuiWindow *bgwin = ImGui::GetCurrentWindow();
		//ImGui::SetWindowSize(io.DisplaySize);
		ImDrawList *drawlist = ImGui::GetWindowDrawList();
		//drawlist->AddText( ImVec2(400,400), ImColor(1.0f,1.0f,1.0f,1.0f), "Text in Background Layer" );
		drawlist->AddText( ImGui::GetMousePos(), ImColor(1.0f,1.0f,1.0f,1.0f), "Text in Background Layer" );
		//float center_w = ImGui::GetWindowWidth() / 2;
		//float center_h = ImGui::GetWindowHeight() / 2;
		//drawlist->AddLine(ImVec2(center_w - 20, center_h), ImVec2(center_w - 10, center_h), 0xffffffff, 2.0);
		//drawlist->AddLine(ImVec2(center_w + 20, center_h), ImVec2(center_w + 10, center_h), 0xffffffff, 2.0);
		//if (leetmenu->callback_ingame)
		//	leetmenu->callback_ingame();
		//ImGui::End();
}

void imgui_frame_end() {


			//ImGuiIO &io = ImGui::GetIO();
			//ImVec2 a = ImGui::GetMousePos();
			//ImVec2 b = io.DisplaySize / 2;
			//imgui_line(&a, &b, 0xff00ffff, 2);

	ImGui::End();

        //// 1. Show a simple window.
        //// Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets automatically appears in a window called "Debug".
        //{
        //    static float f = 0.0f;
        //    static int counter = 0;
        //    ImGui::Text("Hello, world!");                           // Display some text (you can use a format string too)
        //    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
        //    ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
		//
        //    ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our windows open/close state
        //    ImGui::Checkbox("Another Window", &show_another_window);
		//
        //    if (ImGui::Button("Button"))                            // Buttons return true when clicked (NB: most widgets return true when edited/activated)
        //        counter++;
        //    ImGui::SameLine();
        //    ImGui::Text("counter = %d", counter);
		//
        //    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        //}
		//
        //// 2. Show another simple window. In most cases you will use an explicit Begin/End pair to name your windows.
        //if (show_another_window)
        //{
        //    ImGui::Begin("Another Window", &show_another_window);
        //    ImGui::Text("Hello from another window!");
        //    if (ImGui::Button("Close Me"))
        //        show_another_window = false;
        //    ImGui::End();
        //}
		//
        //// 3. Show the ImGui demo window. Most of the sample code is in ImGui::ShowDemoWindow(). Read its code to learn more about Dear ImGui!
        //if (show_demo_window)
        //{
        //    ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver); // Normally user code doesn't need/want to call this because positions are saved in .ini file anyway. Here we just want to make the demo initial state a bit more friendly!
        //    ImGui::ShowDemoWindow(&show_demo_window);
        //}

		//bool hideNormal = GetAsyncKeyState(VK_F10) & 0x8000;
		//if (hideNormal == false)
		{
			imgui_default_docks();
			render_all_wz4_docks();
		
		}

		//RootDock(ImVec2(0,0), ImGui::GetIO().DisplaySize);
		//bool closed = true;
		//if (BeginDock("test", &closed)) {
		//	//dock->imgui();
		//	ImGui::Button("asd");
		//	ImGui::Button("asd");
		//	ImGui::Button("asd");
		//}
		//EndDock();
		//if (BeginDock("testa sd", &closed)) {
		//	//dock->imgui();
		//	ImGui::Button("asd");
		//	ImGui::Button("addsd");
		//	ImGui::Button("asd");
		//}
		//EndDock();



        // Rendering
        ImGui::EndFrame();
#if 1
        DXDev->SetRenderState(D3DRS_ZENABLE, false);
        DXDev->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
        DXDev->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
#else
        DXDev->SetRenderState(D3DRS_ZENABLE, true);
        DXDev->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
        DXDev->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
#endif


        D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x*255.0f), (int)(clear_color.y*255.0f), (int)(clear_color.z*255.0f), (int)(clear_color.w*255.0f));
        //DXDev->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
		//DXDev->Clear(0, NULL, D3DCLEAR_TARGET, clear_col_dx, 1.0f, 0);
        if (DXDev->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            DXDev->EndScene();
        }

	

	//}
}


void imgui_present() {
	HRESULT result = DXDev->Present(NULL, NULL, NULL, NULL);
	return;


		//sSetRenderClipping(&Region3D.Rects[0],Region3D.Rects.GetCount());
		//sRect rect(0,0,1000,1000);
		//sSetRenderClipping(&rect, 1);
		///Region3D.Clear();
		ImDrawData *draw_data = ImGui::GetDrawData();
		//ImGui::GetWindowDrawList();
    // Render command lists
    int vtx_offset = 0;
    int idx_offset = 0;
    ImVec2 pos = draw_data->DisplayPos;
    for (int n = 0; n < draw_data->CmdListsCount; n++)
    {
        const ImDrawList* cmd_list = draw_data->CmdLists[n];
        for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++)
        {
            const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
            if (pcmd->UserCallback)
            {
                pcmd->UserCallback(cmd_list, pcmd);
            }
            else
            {
                //const RECT r = { (LONG)(pcmd->ClipRect.x - pos.x), (LONG)(pcmd->ClipRect.y - pos.y), (LONG)(pcmd->ClipRect.z - pos.x), (LONG)(pcmd->ClipRect.w - pos.y) };
                //g_pd3dDevice->SetTexture(0, (LPDIRECT3DTEXTURE9)pcmd->TextureId);
                //g_pd3dDevice->SetScissorRect(&r);
                //g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, vtx_offset, 0, (UINT)cmd_list->VtxBuffer.Size, idx_offset, pcmd->ElemCount/3);

				LONG a = (LONG)(pcmd->ClipRect.x - pos.x);
				LONG b = (LONG)(pcmd->ClipRect.y - pos.y);
				LONG c = (LONG)(pcmd->ClipRect.z - pos.x);
				LONG d = (LONG)(pcmd->ClipRect.w - pos.y);
				//sRect rect;
				//rect.x0 = a / 2;
				//rect.y0 = b / 2;
				//rect.x1 = c / 2;
				//rect.y1 = d / 2;
				//sSetRenderClipping(&rect, 1);
				//AddPresentClip(&rect);
            }
            idx_offset += pcmd->ElemCount;
        }
        vtx_offset += cmd_list->VtxBuffer.Size;
    }



       // result = DXDev->Present(NULL, NULL, NULL, (RGNDATA *) RenderClippingData);
		
		
}