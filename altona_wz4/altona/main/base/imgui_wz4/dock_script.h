#ifndef DOCK_SCRIPT
#define DOCK_SCRIPT

#include "../imgui/include_imgui.h"
#include "../imgui_docks/dock.h"
#include <string>
#include "../imgui/imgui_dock.h"

class DockScript : public Dock {
public:
	DockScript();
	virtual const char *label();
	virtual void imgui();
};

#endif