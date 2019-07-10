#include <GLFW/glfw3.h>

#include "fwMainFrame.h"

fwMainFrame::fwMainFrame(
	GLFWwindow* window, int row, int column,
	const std::initializer_list<int>& widths,
	const std::initializer_list<int>& heights) :
	fwFrame(row, column, widths, heights),
	m_windowPos{ 0, 0 }, m_cursor{ 0, 0 },
	m_elementUnderCursor(nullptr), m_elementFocused(nullptr),
	m_glfwWindow(window)
{
	glfwGetWindowPos(window, &m_windowPos[0], &m_windowPos[1]);
	glfwGetWindowSize(window, &m_windowSize[0], &m_windowSize[1]);
	setWidgetWidth(m_windowSize[0]), setWidgetHeight(m_windowSize[1]);
}

void fwMainFrame::onRepaint()
{
	if (glfwGetCurrentContext() != m_glfwWindow)
		glfwMakeContextCurrent(m_glfwWindow);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glOrtho(0, getWindowWidth(), 0, getWindowHeight(), -1, 1);
	fwFrame::onRepaint();
	glfwSwapBuffers(m_glfwWindow);
}

void fwMainFrame::onWindowMove(int x, int y)
{
	m_windowPos[0] = x, m_windowPos[1] = y;
}

void fwMainFrame::onWindowResize(int width, int height)
{
	setWidgetWidth(m_windowSize[0] = width);
	setWidgetHeight(m_windowSize[1] = height);
}

void fwMainFrame::onCursorMove(int xpos, int ypos)
{
	fwLeafWidget* fwLocateLeafWidget(fwFrame * frame, int xpos, int ypos);
	m_cursor[0] = xpos, m_cursor[1] = ypos;
	if (m_elementUnderCursor != nullptr && m_elementUnderCursor->pointInside(xpos, ypos)) {
		m_elementUnderCursor->onCursorMove(xpos - m_elementUnderCursor->getWidgetXPos(),
											   ypos - m_elementUnderCursor->getWidgetYPos());
	}
	else {
		fwLeafWidget* widget = fwLocateLeafWidget(this, xpos, ypos);
		if(m_elementUnderCursor != nullptr) m_elementUnderCursor->onCursorEnter(false);
		m_elementUnderCursor = widget;
		if(m_elementUnderCursor != nullptr) m_elementUnderCursor->onCursorEnter(true);
	}
}

void fwMainFrame::onCursorEnter(int enter)
{
	if (enter == GLFW_FALSE) {
		m_cursor[0] = -1, m_cursor[1] = -1;
		if(m_elementUnderCursor != nullptr) m_elementUnderCursor->onCursorEnter(false);
		m_elementUnderCursor = nullptr;
	}
}

void fwMainFrame::onMouseButtonChange(int button, int action, int mods)
{
	if(action == GLFW_PRESS && m_elementUnderCursor != m_elementFocused) {
		if(m_elementFocused != nullptr) m_elementFocused->onFocus(false);
		m_elementFocused = m_elementUnderCursor;
		if(m_elementFocused != nullptr) m_elementFocused->onFocus(true);
	}
	if(m_elementFocused != nullptr) m_elementFocused->onMouseButtonChange(button, action, mods);
}

void fwMainFrame::onScroll(double xoffset, double yoffset)
{
	if(m_elementUnderCursor)
		m_elementUnderCursor->onScroll(xoffset, yoffset);
	
	// Policy Needed
	// if(m_elementFocused)
	//	m_elementFocused->scrollCallback(xoffset, yoffset);
}

void fwMainFrame::onFileDrop(int path_count, const char* paths[])
{
	if(m_elementUnderCursor) {
		m_elementUnderCursor->onFileDrop(path_count, paths);
	}
}

void fwMainFrame::onKeyChange(int key, int scancode, int action, int mods)
{
	if(m_elementFocused) {
		m_elementFocused->onKeyChange(key, scancode, action, mods);
	}
}

void fwMainFrame::onInput(unsigned int codepoint, int mods)
{
	if(m_elementFocused) {
		m_elementFocused->onInput(codepoint, mods);
	}
}

void fwInitCallbacks(GLFWwindow* window) {

	glfwSetWindowPosCallback(window,[](GLFWwindow* window, int x, int y) {
		((fwMainFrame*)glfwGetWindowUserPointer(window))->onWindowMove(x, y);
	});

	glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
		((fwMainFrame*)glfwGetWindowUserPointer(window))->onWindowResize(width, height);
	});

	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos){
		((fwMainFrame*)glfwGetWindowUserPointer(window))->onCursorMove((int)xpos, (int)ypos);
	});
	glfwSetCursorEnterCallback(window, [](GLFWwindow* window, int enter){
		((fwMainFrame*)glfwGetWindowUserPointer(window))->onCursorEnter(enter);
	});
	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods){
		((fwMainFrame*)glfwGetWindowUserPointer(window))->onMouseButtonChange(button, action, mods);
	});
	glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset) {
		((fwMainFrame*)glfwGetWindowUserPointer(window))->onScroll(xoffset, yoffset);
	});
	glfwSetDropCallback(window, [](GLFWwindow* window, int path_count, const char* paths[]){
		((fwMainFrame*)glfwGetWindowUserPointer(window))->onFileDrop(path_count, paths);
	});
	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
		((fwMainFrame*)glfwGetWindowUserPointer(window))->onKeyChange(key, scancode, action, mods);
	});
	glfwSetCharModsCallback(window, [](GLFWwindow* window, unsigned int codepoint, int mods) {
		((fwMainFrame*)glfwGetWindowUserPointer(window))->onInput(codepoint, mods);
	});
}