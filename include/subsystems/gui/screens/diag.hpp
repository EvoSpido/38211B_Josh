#include "display/lvgl.h"

void diagScreen();

void setDiagText(int line, const char* string);
void dispAutoDiag();

extern lv_obj_t* scrDiagLabel;

extern lv_obj_t* scrDiagDispBtn;