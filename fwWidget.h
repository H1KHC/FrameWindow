/**
 * @file fwWidget.h
 * @author H1MSK (ksda47832338@outlook.com)
 * @brief Defination of class fwWidget
 * @version 0.0.2
 * @date 2019-07-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef FW_WIDGET_H
#define FW_WIDGET_H

class fwFrame;
class fwMainFrame;

/**
 * @brief Abstruct base class of widgets
 */
class fwWidget
{
public:
	/**
	 * @brief Definations of widget type
	 */
	enum class WidgetType
	{
		InvalidWidget,
		LeafWidget,
		Frame,
		MainFrame
	};

private:
	/**
	 * @brief parent node, `nullptr` if `this` is fwMainWindow or is invalid
	 */
	fwWidget* m_parent;

	/**
	 * @brief pointer to the mainFrame containing this widget
	 */
	fwMainFrame* m_owner;

	/**
	 * @brief depth of this widget in the frame tree
	 */
	int m_depth;

	/**
	 * @brief position when rendering
	 */
	int m_pos[2];

	/**
	 * @brief size when rendering
	 */
	int m_size[2];

protected:
	/**
	 * @brief Set the Widget X Pos
	 */
	void setWidgetXPos  (int x) { m_pos[0]  = x; }

	/**
	 * @brief Set the Widget Y Pos
	 */
	void setWidgetYPos  (int y) { m_pos[1]  = y; }

	/**
	 * @brief Set the Widget Width
	 */
	void setWidgetWidth (int w) { m_size[0] = w; }

	/**
	 * @brief Set the Widget Height
	 */
	void setWidgetHeight(int h) { m_size[1] = h; }

	/**
	 * @brief Get the parent widget
	 */
	const fwWidget* getParent()   const { return m_parent; }

	/**
	 * @brief Get the owner mainFrame of this widget
	 */
	const fwMainFrame* getOwner() const { return m_owner; }

	/**
	 * @brief Construct a new fwWidget object
	 *
	 * @param isMainFrame whether this widget is fwMainWindow,
	 *  used to determine whether m_owner is itself or a nullptr
	 */
	fwWidget(bool isMainFrame = false) :
				 m_parent(nullptr),
				 m_owner(isMainFrame ? (fwMainFrame*)this : nullptr),
				 m_depth(-1), m_pos{ -1, -1 }, m_size{ -1, -1 } {};

	/**
	 * @brief default destructor
	 */
	virtual ~fwWidget() { };

	/**
	 * @brief Attach current widget to the frame and make this widget available
	 * 
	 * @param frame  parent frame
	 * @param row    row count in parent frame
	 * @param column column count in parent frame
	 */
	void attachTo(fwFrame* frame, int row, int column);

	/**
	 * @brief give it access to attach child node to itself
	 */
	friend class fwFrame;

public:
	/**
	 * @brief Get the Widget X Pos
	 */
	int getWidgetXPos()     const { return m_pos[0]; }

	/**
	 * @brief Get the Widget Y Pos
	 */
	int getWidgetYPos()     const { return m_pos[1]; }

	/**
	 * @brief Get the Widget Width
	 */
	int getWidgetWidth()    const { return m_size[0]; }

	/**
	 * @brief Get the Widget Height
	 */
	int getWidgetHeight()   const { return m_size[1]; }

	/**
	 * @brief Display callback
	 */
	virtual void onRepaint() = 0;

	/**
	 * @brief Returns the type of this widget
	 */
	virtual WidgetType type() const {
		return WidgetType::InvalidWidget;
	}

	/**
	 * @brief Test if point(x, y) is inside this widget
	 * 
	 * @param x x coordinate of the point
	 * @param y y coordinate of the point
	 * @return true The point is inside
	 * @return false The point is outside
	 */
	bool pointInside(int x, int y) const {
		return x >= m_pos[0] && x < (m_pos[0] + m_size[0]) &&
			   y >= m_pos[1] && y < (m_pos[1] + m_size[1]);
	}
};

#endif // FW_WIDGET_H
