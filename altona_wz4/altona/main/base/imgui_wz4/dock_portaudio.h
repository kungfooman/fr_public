#ifndef DOCK_PORTAUDIO
#define DOCK_PORTAUDIO

#include "../imgui/include_imgui.h"
#include "../imgui_docks/dock.h"
#include <string>
#include "../imgui/imgui_dock.h"

class DockPortaudio : public Dock {
public:
	DockPortaudio();
	virtual const char *label();
	virtual void imgui();
};

#endif