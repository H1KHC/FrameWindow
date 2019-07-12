/**
 * @file fwFrame.h
 * @author H1MSK (ksda47832338@outlook.com)
 * @brief Defination of class fwFrame
 * @version 0.0.2
 * @date 2019-07-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef FW_FRAME_H
#define FW_FRAME_H

#include <functional>
#include <vector>

#include "Containers/BIT.h"

#include "fwWidget.h"

/**
 * @brief The frame
 */
class fwFrame : public fwWidget
{
	/**
	 * @brief Restores the number of columns this frame has
	 */
	int m_cols;

	/**
	 * @brief Restores the number of rows this frame has
	 */
	int m_rows;

	/**
	 * @brief Restores the width of each column
	 */
	BIT<int> m_columnWidth;

	/**
	 * @brief Restores the height of each row
	 */
	BIT<int> m_rowHeight;

	/**
	 * @brief Restores the pointers to all the elements
	 */
	std::vector<std::vector<fwWidget*>> m_elements;

protected:
	/**
	 * @brief Display callback
	 */
	void onRepaint();

public:
	/**
	 * @brief Get the x-coordinate of the column, relative to the left side of
	 *  the content area.
	 * 
	 * @param column The column number
	 * @return int The x-coordinate
	 */
	int getColumnXPos(int column) const { return getWidgetXPos() + m_columnWidth.prefix(column - 1); }

	/**
	 * @brief Get the y-coordinate of the row, relative to the up side of
	 *  the content area.
	 * 
	 * @param row The row number
	 * @return int The y-coordinate
	 */
	int getRowYPos(int row)		  const { return getWidgetYPos() + m_rowHeight.prefix(row - 1); }

	/**
	 * @brief Get the width of indicated column
	 * 
	 * @param column The column number
	 * @return int The width
	 */
	int getColumnWidth(int column) const { return m_columnWidth.at(column); }

	/**
	 * @brief Get the height of the indicated row
	 * 
	 * @param row the row number
	 * @return int The height
	 */
	int getRowHeight(int row)   const { return m_rowHeight.at(row); }

	/**
	 * @brief Get the number of columns this frame has
	 * 
	 * @return int The column count
	 */
	int getColumnCount()     const { return m_cols; }

	/**
	 * @brief Get the number of rows this frame has
	 * 
	 * @return int The row count
	 */
	int getRowCount()		 const { return m_rows; }

	/**
	 * @brief Get the indicated element
	 * 
	 * @param row The row number where the element locates
	 * @param column The column number where the element locates
	 * @return const fwWidget* The pointer to the element
	 */
	const fwWidget* getElement(int row, int column) const {
		return m_elements[row][column];
	}

	/**
	 * @brief Get the indicated element
	 * 
	 * @param row The row number where the element locates
	 * @param column The column number where the element locates
	 * @return const fwWidget* The pointer to the element
	 */
	fwWidget* getElement(int row, int column) {
		return m_elements[row][column];
	}

	/**
	 * @brief Replace the element in the indicated location
	 * 
	 * @warning Possible memory leak as the old element won't be deleted
	 * 
	 * @param row The row number where the element locates
	 * @param column The column number where the element locates
	 * @param widget The new widget to replace the current element
	 */
	void replaceElement(int row, int column, fwWidget* widget) {
		m_elements[row][column] = widget;
		widget->attachTo(this, row, column);
	}

	/**
	 * @brief Returns the type of this widget
	 */
	virtual WidgetType type() const override
	{
		return WidgetType::Frame;
	}

	/**
	 * @brief Construct a new fwFrame object, only for internal use
	 *
	 * @param row The number of the row count
	 * @param column The number of the column count
	 * @param widths The number of width, in pixel, of each row
	 * @param heights The number of height, in pixel, of each row
	 */
	fwFrame(bool isMainWidget, int row, int column,
		const std::initializer_list<int>& widths,
		const std::initializer_list<int>& heights) :
		fwWidget(isMainWidget),
		m_cols(column), m_rows(row), m_columnWidth(column, widths), m_rowHeight(row, heights),
		m_elements(row, std::vector<fwWidget*>(column, nullptr))
	{
	};

public:
	/**
	 * @brief Construct a new fwFrame object
	 * 
	 * @param row The number of the row count
	 * @param column The number of the column count
	 * @param widths The number of width, in pixel, of each row
	 * @param heights The number of height, in pixel, of each row
	 */
	fwFrame(int row, int column,
		const std::initializer_list<int>& widths,
		const std::initializer_list<int>& heights) :
		fwFrame(false, row, column, widths, heights)
	{
	};

protected:
	/**
	 * @brief Default destructor, deletes each element this frame has
	 */
	virtual ~fwFrame() {
		for (auto& Column : m_elements) {
			for (fwWidget* element : Column) {
				delete element;
			}
		}
	}
};

#endif // FW_FRAME_H
