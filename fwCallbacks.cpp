#include <GLFW/glfw3.h>
#include "fwMainFrame.h"
#include "fwLeafWidget.h"

void fwMainFrame::windowPositionCallback(int x, int y)
{
	windowPos[0] = x, windowPos[1] = y;
}

void fwMainFrame::windowSizeCallback(int width, int height)
{
	size[0] = width, size[1] = height;
}

void fwMainFrame::cursorMoveCallback(int xpos, int ypos)
{
	fwLeafWidget* fwLocateLeafWidget(fwFrame * frame, int xpos, int ypos);
	cursor[0] = xpos, cursor[1] = ypos;
	if (elementUnderCursor == nullptr || !elementUnderCursor->pointInside(xpos, ypos)) {
		fwLeafWidget* widget = fwLocateLeafWidget(this, xpos, ypos);
		if(elementUnderCursor != nullptr) elementUnderCursor->mouseEnterCallback(false);
		elementUnderCursor = widget;
		if(elementUnderCursor != nullptr) elementUnderCursor->mouseEnterCallback(true);
	}
}

void fwMainFrame::cursorEnterCallback(int enter)
{
	if (enter == GLFW_FALSE) {
		cursor[0] = -1, cursor[1] = -1;
		if(elementUnderCursor != nullptr) elementUnderCursor->mouseEnterCallback(false);
		elementUnderCursor = nullptr;
	}
}

void fwMainFrame::mouseButtonCallback(int button, int action, int mods)
{
	if(action == GLFW_PRESS && elementUnderCursor != elementFocused) {
		if(elementFocused != nullptr) elementFocused->focusCallback(false);
		elementFocused = elementUnderCursor;
		if(elementFocused != nullptr) elementFocused->focusCallback(true);
	}
	if(elementFocused != nullptr) elementFocused->mouseButtonCallback(button, action, mods);
}

void fwMainFrame::scrollCallback(double xoffset, double yoffset)
{
	if(elementUnderCursor)
		elementUnderCursor->scrollCallback(xoffset, yoffset);
	
	// Policy Needed
	// if(elementFocused)
	//	elementFocused->scrollCallback(xoffset, yoffset);
}

void fwMainFrame::fileDropCallback(int path_count, const char* paths[])
{
	if(elementUnderCursor) {
		elementUnderCursor->fileDropCallback(path_count, paths);
	}
}

void fwMainFrame::keyCallback(int key, int scancode, int action, int mods)
{
	if(elementFocused) {
		elementFocused->keyCallback(key, scancode, action, mods);
	}
}

void fwMainFrame::charModsCallback(unsigned int codepoint, int mods)
{
	if(elementFocused) {
		elementFocused->charModsCallback(codepoint, mods);
	}
}

void fwInitCallbacks(GLFWwindow* window) {

	glfwSetWindowPosCallback(window,[](GLFWwindow* window, int x, int y) {
		((fwMainFrame*)glfwGetWindowUserPointer(window))->windowPositionCallback(x, y);
	});

	glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
		((fwMainFrame*)glfwGetWindowUserPointer(window))->windowSizeCallback(width, height);
	});

	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos){
		((fwMainFrame*)glfwGetWindowUserPointer(window))->cursorMoveCallback((int)xpos, (int)ypos);
	});
	glfwSetCursorEnterCallback(window, [](GLFWwindow* window, int enter){
		((fwMainFrame*)glfwGetWindowUserPointer(window))->cursorEnterCallback(enter);
	});
	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods){
		((fwMainFrame*)glfwGetWindowUserPointer(window))->mouseButtonCallback(button, action, mods);
	});
	glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset) {
		((fwMainFrame*)glfwGetWindowUserPointer(window))->scrollCallback(xoffset, yoffset);
	});
	glfwSetDropCallback(window, [](GLFWwindow* window, int path_count, const char* paths[]){
		((fwMainFrame*)glfwGetWindowUserPointer(window))->fileDropCallback(path_count, paths);
	});
	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
		((fwMainFrame*)glfwGetWindowUserPointer(window))->keyCallback(key, scancode, action, mods);
	});
	glfwSetCharModsCallback(window, [](GLFWwindow* window, unsigned int codepoint, int mods) {
		((fwMainFrame*)glfwGetWindowUserPointer(window))->charModsCallback(codepoint, mods);
	});
}