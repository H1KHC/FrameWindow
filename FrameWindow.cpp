#include <GLFW/glfw3.h>
#include "fwMainFrame.h"

#include "FrameWindow.h"

fwFrame* fwInitFrameWindow(GLFWwindow* window, int rowCount, int columnCount,
	const std::initializer_list<int>& widths,
	const std::initializer_list<int>& heights)
{
	void fwInitCallbacks(GLFWwindow * window);
	int x, y, w, h;
	glfwGetWindowPos(window, &x, &y);
	glfwGetWindowSize(window, &w, &h);
	fwMainFrame* mf = new fwMainFrame(x, y, w, h, window, rowCount, columnCount, widths, heights);
	glfwSetWindowUserPointer(window, mf);

	fwInitCallbacks(window);
	return mf;
}

fwFrame* fwInitWidgetAsFrame(fwFrame* parent, int row, int column, int rowCount, int columnCount, const std::initializer_list<int>& widths, const std::initializer_list<int>& heights)
{
	if (parent->getElement(row, column) != nullptr) return nullptr;
	fwFrame* newFrame = new fwFrame(rowCount, columnCount, widths, heights);
	parent->replaceElement(row, column, newFrame);
	
	return newFrame;
}

bool fwInitWidgetAsLeaf(fwFrame* parent, int row, int column, fwLeafWidget* leaf)
{
	if (parent->getElement(row, column) != nullptr) return false;
	parent->replaceElement(row, column, leaf);
	return true;
}

void fwUpdate(fwFrame* mainFrame)
{
	if(mainFrame->type() == fwWidget::WidgetType::MainFrame)
		((fwMainFrame*)mainFrame)->display();
}

fwLeafWidget* fwRecursivelyFindLeafWidget(fwWidget* widget, int xpos, int ypos) {
	if (widget->type() == fwWidget::WidgetType::LeafWidget) return (fwLeafWidget*)widget;

	fwFrame* frame = (fwFrame*)widget;
	int row = frame->getRowCount() - 1, col = frame->getColumnCount() - 1;

	for (int i = 1, rows = frame->getRowCount(); i < rows; ++i) {
		if (frame->getYPos(i) > ypos) {
			row = i - 1;
			break;
		}
	}
	for (int i = 1, cols = frame->getColumnCount(); i < cols; ++i){
		if (frame->getXPos(i) > xpos) {
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
