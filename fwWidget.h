#pragma once

class fwFrame;
class fwWidget
{
protected:
	fwWidget* parent;
	int depth, pos[2], size[2];
	fwWidget() : parent(nullptr), depth(-1), pos{ -1, -1 }, size{ -1, -1 } {};

	/**
	 * @brief Construct a new Widget object, only called when constructing fwMainFrame
	 * 
	 * @param w width of the window
	 * @param h height of the window
	 */
	fwWidget(int w, int h) : parent(nullptr), depth(1), pos{ 0, 0 }, size{ w, h } {};

	/**
	 * @brief Attach current widget to the frame, called _only_ in the parent frame
	 * 
	 * @param frame  parent frame
	 * @param row    row count in parent frame
	 * @param column column count in parent frame
	 */
	void attachTo(fwFrame* frame, int row, int column);
	friend class fwFrame;

public:
	enum class WidgetType
	{
		LeafWidget,
		Frame,
		MainFrame
	};
	virtual void display() = 0;
	virtual WidgetType type() const = 0;

	bool pointInside(int x, int y) const {
		return x >= pos[0] && x < (pos[0] + size[0]) &&
			   y >= pos[1] && y < (pos[1] + size[1]);
	}
};
