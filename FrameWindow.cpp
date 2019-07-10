#include <GLFW/glfw3.h>
#include "FrameWindow.h"

fwFrame* fwInitWidgetAsFrame(fwFrame* parent, int row, int column, int rowCount, int columnCount, const std::initializer_list<int>& widths, const std::initializer_list<int>& heights)
{
	if (parent->getElement(row, column) != nullptr) return nullptr;
	fwFrame* newFrame = new fwFrame(rowCount, columnCount, widths, heights);
	parent->replaceElement(row, column, newFrame);
	
	return newFrame;
}

fwWidget* fwSetWidgetAsLeaf(fwFrame* parent, int row, int column, fwLeafWidget* leaf)
{
	fwWidget* oldElement = parent->getElement(row, column);
	parent->replaceElement(row, column, leaf);
	return oldElement;
}

void fwUpdate(fwMainFrame* mainFrame)
{
	if(mainFrame->type() == fwWidget::WidgetType::MainFrame)
		((fwMainFrame*)mainFrame)->onRepaint();
}

fwLeafWidget* fwRecursivelyFindLeafWidget(fwWidget* widget, int xpos, int ypos) {
	if (widget->type() == fwWidget::WidgetType::LeafWidget) return (fwLeafWidget*)widget;

	fwFrame* frame = (fwFrame*)widget;
	int row = frame->getRowCount() - 1, col = frame->getColumnCount() - 1;

	for (int i = 1, rows = frame->getRowCount(); i < rows; ++i) {
		if (frame->getRowYPos(i) > ypos) {
			row = i - 1;
			break;
		}
	}
	for (int i = 1, cols = frame->getColumnCount(); i < cols; ++i){
		if (frame->getColumnXPos(i) > xpos) {
			col = i - 1;
			break;
		}
	}

	return fwRecursivelyFindLeafWidget(frame->getElement(row, col), xpos, ypos);
}

fwLeafWidget* fwLocateLeafWidget(fwFrame* frame, int xpos, int ypos)
{
	if (!frame->pointInside(xpos, ypos)) return nullptr;
	return fwRecursivelyFindLeafWidget(frame, xpos, ypos);
}
