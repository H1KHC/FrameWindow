#pragma once

#include <functional>
#include <vector>

#include "Containers/BIT.h"

#include "fwWidget.h"

class fwLeafWidget;
class fwFrame : public fwWidget
{
protected:
	int cols, rows;
	BIT<int> columnWidth, rowHeight;
	std::vector<std::vector<fwWidget*>> elements;

	void display();

public:
	int getXPos(int column)  const { return pos[0] + columnWidth.prefix(column - 1); }
	int getYPos(int row)     const { return pos[1] + rowHeight.prefix(row - 1); }
	int getWidth(int column) const { return columnWidth.at(column); }
	int getHeight(int row)   const { return rowHeight.at(row); }
	int getColumnCount()     const { return cols; }
	int getRowCount()		 const { return rows; }

	const fwWidget* getElement(int row, int column) const {
		return elements[row][column];
	}
	fwWidget* getElement(int row, int column) {
		return elements[row][column];
	}
	void replaceElement(int row, int column, fwWidget* widget) {
		fwWidget*& element = elements[row][column];
		if (element != nullptr) delete element;
		element = widget;
		widget->attachTo(this, row, column);
	}

	virtual WidgetType type() const override
	{
		return WidgetType::Frame;
	}

	fwFrame(int row, int column,
		const std::initializer_list<int>& widths,
		const std::initializer_list<int>& heights) :
		rows(row), cols(column), columnWidth(column, widths), rowHeight(row, heights),
		elements(row, std::vector<fwWidget*>(column, nullptr))
	{
	};

	fwFrame(int w, int h,
		int row, int column,
		const std::initializer_list<int>& widths,
		const std::initializer_list<int>& heights) :
		rows(row), cols(column), columnWidth(column, widths), rowHeight(row, heights),
		elements(row, std::vector<fwWidget*>(column, nullptr)),
		fwWidget(w, h)
	{
	};
};

