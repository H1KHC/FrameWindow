/**
 * @file fwLeafWidget.h
 * @author H1MSK (ksda47832338@outlook.com)
 * @brief Defination of class fwLeafWidget
 * @version 0.0.2
 * @date 2019-07-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef FW_LEAF_WIDGET_H
#define FW_LEAF_WIDGET_H
#include "fwWidget.h"
#include "fwFrame.h"

/**
 * @brief The leaf widget
 */
class fwLeafWidget :
	public fwWidget
{
protected:
	/**
	 * @brief Default constructor
	 */
	fwLeafWidget() {}
	
	friend class fwMainFrame;

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4100)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
	/**
	 * @brief Cursor move callback
	 * 
	 * @param xpos The new cursor x-coordinate, relative to the left edge of
	 *  the content area.
	 * @param ypos The new cursor y-coordinate, relative to the top edge of the
	 *  content area.
	 */
	virtual void onCursorMove(int xpos, int ypos) { }
	
	/**
	 * @brief Cursor enter/leave callback
	 * 
	 * @param enter `GLFW_TRUE` if the cursor entered the widget's content
	 *  area, or `GLFW_FALSE` if it left it.
	 */
	virtual void onCursorEnter(bool enter) { }

	/**
	 * @brief Widget focus callback
	 * 
	 * @param focus `GLFW_TRUE` if the widget was given input focus, or
	 *  `GLFW_FALSE` if it lost it.
	 */
	virtual void onFocus(bool focus) { }

	/**
	 * @brief Mouse button callback
	 * 
	 * @param button The mouse button that was pressed or released
	 * @param action One of `GLFW_PRESS` or `GLFW_RELEASE`.
	 * @param mods Bit field describing which modifier keys were held down.
	 */
	virtual void onMouseButtonChange(int button, int action, int mods) { }

	/**
	 * @brief Scroll callback 
	 * 
	 * @param xoffset The scroll offset along the x-axis.
	 * @param yoffset The scroll offset along the y-axis.
	 */
	virtual void onScroll(double xoffset, double yoffset) { }

	/**
	 * @brief File drop callback
	 * 
	 * @param path_count The number of dropped paths.
	 * @param paths The UTF-8 encoded file and/or directory path names.
	 */
	virtual void onFileDrop(int path_count, const char* paths[]) { }

	/**
	 * @brief Keyboard key callbacks
	 * 
	 * @param key The keyboard key that was pressed or released.
	 * @param scancode The system-specific scancode of the key.
	 * @param action action `GLFW_PRESS`, `GLFW_RELEASE` or `GLFW_REPEAT`.
	 * @param mods Bit field describing which modifier keys were held down.
	 */
	virtual void onKeyChange(int key, int scancode, int action, int mods) { }

	/**
	 * @brief Char callbacks
	 * 
	 * @param codepoint The Unicode code point of the character.
	 * @param mods Bit field describing which modifier keys were held down.
	 */
	virtual void onInput(unsigned int codepoint, int mods) { }

	/**
	 * @brief Display callback
	 */
	virtual void onRepaint() = 0;
#ifdef _MSC_VER
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
public:
	/**
	 * @brief Returns the type of this widget
	 */
	WidgetType type() const override {
		return WidgetType::LeafWidget;
	}

	/**
	 * @brief Test if the widget is accessible from any mainFrame
	 * 
	 * @return true This widget is accessible
	 * @return false This widget isn't accessible
	 */
	bool available() { return getOwner() != nullptr; }
};

#endif // FW_LEAF_WIDGET_H
