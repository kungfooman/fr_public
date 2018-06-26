#pragma once

#include "../ccall.h"

CCALL void imgui_frame_start();
CCALL void imgui_frame_end();
CCALL void imgui_present();
CCALL void imgui_line(ImVec2 *a, ImVec2 *b, unsigned int color, float thickness);
CCALL void imgui_point(ImVec2 *a, float radius, unsigned int color, int num_segments);
