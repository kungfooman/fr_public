#ifndef DOCK_ANGELSCRIPT
#define DOCK_ANGELSCRIPT

#include "../imgui/include_imgui.h"
#include "../imgui_docks/dock.h"
#include <string>
#include "../imgui/imgui_dock.h"

class DockAngelscript : public Dock {
public:
	DockAngelscript();
	virtual const char *label();
	virtual void imgui();
};

#endif