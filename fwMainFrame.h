/**
 * @file fwMainFrame.h
 * @author H1MSK (ksda47832338@outlook.com)
 * @brief Defination of class fwMainFrame
 * @version 0.0.2
 * @date 2019-07-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef FW_MAIN_FRAME_H
#define FW_MAIN_FRAME_H
#include "fwFrame.h"
#include "fwLeafWidget.h"

struct GLFWwindow;

/**
 * @brief The main frame
 */
class fwMainFrame :
	public fwFrame
{
	/**
	 * @brief Restores the position of the glfwWindow
	 */
	int m_windowPos[2], m_windowSize[2];

	/**
	 * @brief Restores the position of the cursor in the window
	 */
	int m_cursor[2];

	/**
	 * @brief Restores the element under cursor
	 */
	fwLeafWidget* m_elementUnderCursor;

	/**
	 * @brief Restores the focused element
	 */
	fwLeafWidget* m_elementFocused;

	/**
	 * @brief Restores the pointer to the glfw window handle
	 */
	GLFWwindow* m_glfwWindow;

public:

	/**
	 * @brief Get the Window X Pos
	 */
	int getWindowXPos() const { return m_windowPos[0]; }

	/**
	 * @brief Get the Window Y Pos
	 */
	int getWindowYPos() const { return m_windowPos[1]; }

	/**
	 * @brief Get the Window Width
	 */
	int getWindowWidth() const { return getWidgetWidth(); }

	/**
	 * @brief Get the Window Height
	 */
	int getWindowHeight() const { return getWidgetHeight(); }

	/**
	 * @brief Get the glfw window this window bind to
	 */
	GLFWwindow* getGLFWwindow() const { return m_glfwWindow; }

	/**
	 * @brief Returns the type of this widget
	 */
	WidgetType type() const override {
		return WidgetType::MainFrame;
	}

	/**
	 * @brief Window move callback
	 * 
	 * @param x The new x-coordinate, in screen coordinates, of the
	 *  upper-left corner of the content area of the window.
	 * @param y The new y-coordinate, in screen coordinates, of the
	 *  upper-left corner of the content area of the window.
	 */
	void onWindowMove(int x, int y);

	/**
	 * @brief Window resize callback
	 * 
	 * @param width The new width, in screen coordinates, of the window.
	 * @param height The new height, in screen coordinates, of the window.
	 */
	void onWindowResize(int width, int height);

	/**
	 * @brief Cursor move callback
	 * 
	 * @param xpos The new cursor x-coordinate, relative to the left edge of
	 *  the content area.
	 * @param ypos The new cursor y-coordinate, relative to the top edge of the
	 *  content area.
	 */
	void onCursorMove(int xpos, int ypos);
	
	/**
	 * @brief Cursor enter/leave callback
	 * 
	 * @param enter `GLFW_TRUE` if the cursor entered the window's content
	 *  area, or `GLFW_FALSE` if it left it.
	 */
	void onCursorEnter(int enter);

	/**
	 * @brief Mouse button callback
	 * 
	 * @param button The mouse button that was pressed or released
	 * @param action One of `GLFW_PRESS` or `GLFW_RELEASE`.
	 * @param mods Bit field describing which modifier keys were held down.
	 */
	void onMouseButtonChange(int button, int action, int mods);

	/**
	 * @brief Scroll callback 
	 * 
	 * @param xoffset The scroll offset along the x-axis.
	 * @param yoffset The scroll offset along the y-axis.
	 */
	void onScroll(double xoffset, double yoffset);

	/**
	 * @brief File drop callback
	 * 
	 * @param path_count The number of dropped paths.
	 * @param paths The UTF-8 encoded file and/or directory path names.
	 */
	void onFileDrop(int path_count, const char* paths[]);

	/**
	 * @brief Keyboard key callbacks
	 * 
	 * @param key The keyboard key that was pressed or released.
	 * @param scancode The system-specific scancode of the key.
	 * @param action action `GLFW_PRESS`, `GLFW_RELEASE` or `GLFW_REPEAT`.
	 * @param mods Bit field describing which modifier keys were held down.
	 */
	void onKeyChange(int key, int scancode, int action, int mods);

	/**
	 * @brief Char callbacks
	 * 
	 * @param codepoint The Unicode code point of the character.
	 * @param mods Bit field describing which modifier keys were held down.
	 */
	void onInput(unsigned int codepoint, int mods);
	
	/**
	 * @brief Display callback
	 */
	void onRepaint();

	/**
	 * @brief Register callbacks of glfwWindow, called only in constructor,
	 *   after glfwWindowUserPointer is set to this
	 * 
	 * @param window Pointer to the glfwWindow
	 */
	friend void fwInitCallbacks(GLFWwindow* window);

	/**
	 * @brief Construct a new fwMain Frame object
	 * 
	 * @param x The x-coordinate, in screen coordinates, of the upper-left
	 *  corner of the content area of the window.
	 * @param y The y-coordinate, in screen coordinates, of the upper-left
	 *  corner of the content area of the window.
	 * @param w The width, in screen coordinates, of the window.
	 * @param h The height, in screen coordinates, of the window.
	 * @param window The glfwWindow pointer
	 * @param row The number of the row count
	 * @param column The number of the column count
	 * @param widths The number of width, in pixel, of each row
	 * @param heights The number of height, in pixel, of each row
	 */
	fwMainFrame(
		GLFWwindow* window, int row, int column,
		const std::initializer_list<int>& widths,
		const std::initializer_list<int>& heights);

	/**
	 * @brief Default destructor
	 */
	virtual ~fwMainFrame() { }
};

#endif // FW_MAIN_FRAME_H