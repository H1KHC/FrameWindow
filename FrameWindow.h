#pragma once
#include <initializer_list>

extern "C++" {

#include "fwWidget.h"
#include "fwLeafWidget.h"

struct GLFWwindow;
class fwFrame;

fwFrame* fwInitFrameWindow(GLFWwindow* window, int rowCount, int columnCount,
							const std::initializer_list<int>& widths,
							const std::initializer_list<int>& heights);

fwFrame* fwInitWidgetAsFrame(fwFrame* parent, int row, int column,
						int rowCount, int columnCount,
						const std::initializer_list<int>& widths,
						const std::initializer_list<int>& heights);

bool fwInitWidgetAsLeaf(fwFrame* parent, int row, int column, fwLeafWidget* leaf);

void fwUpdate(fwFrame* mainFrame);

fwLeafWidget* fwLocateLeafWidget(fwFrame* frame, int xpos, int ypos);

}
