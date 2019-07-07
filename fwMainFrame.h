#pragma once
#include "fwFrame.h"
struct GLFWwindow;
class fwMainFrame :
	public fwFrame
{
	int windowPos[2], cursor[2];
	fwLeafWidget* elementUnderCursor, *elementFocused;
protected:
	GLFWwindow* glfwWindow;

public:
	fwMainFrame(
		int x, int y, int w, int h,
		GLFWwindow* window, int row, int column,
		const std::initializer_list<int>& widths,
		const std::initializer_list<int>& heights) :
		windowPos{ x, y }, cursor{ 0, 0 },
		elementUnderCursor(nullptr), elementFocused(nullptr),
		glfwWindow(window), fwFrame(w, h, row, column, widths, heights)
	{
	}

	WidgetType type() const override {
		return WidgetType::MainFrame;
	}

	void windowPositionCallback(int x, int y);
	void windowSizeCallback(int width, int height);
	void cursorMoveCallback(int xpos, int ypos);
	void cursorEnterCallback(int enter);
	void mouseButtonCallback(int button, int action, int mods);
	void scrollCallback(double xoffset, double yoffset);
	void fileDropCallback(int path_count, const char* paths[]);
	void keyCallback(int key, int scancode, int action, int mods);
	void charModsCallback(unsigned int codepoint, int mods);
	
	void display();

};
