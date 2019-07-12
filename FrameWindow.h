/**
 * @file FrameWindow.h
 * @author H1MSK (ksda47832338@outlook.com)
 * @brief General header file
 * @version 0.0.2
 * @date 2019-07-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef FRAME_WINDOW_H
#define FRAME_WINDOW_H
#include <initializer_list>

extern "C++" {

struct GLFWwindow;

#include "fwWidget.h"
#include "fwLeafWidget.h"
#include "fwFrame.h"
#include "fwMainFrame.h"

/**
 * @brief Initialize an element in the frame as a subframe
 * 
 * @param parent The pointer to the parent frame
 * @param row The row number where the element locates
 * @param column The column number where the element locates
 * @param rowCount The number of the row count of the subframe
 * @param columnCount The number of the column count of the subframe
 * @param widths The number of width, in pixel, of each row of the fubframe
 * @param heights The number of height, in pixel, of each row of the fubframe
 * @return fwFrame* The pointer to the newly initialized fwFrame
 */
fwFrame* fwInitWidgetAsFrame(fwFrame* parent, int row, int column,
						int rowCount, int columnCount,
						const std::initializer_list<int>& widths,
						const std::initializer_list<int>& heights);

/**
 * @brief Initialize an element in the frame as a leaf
 * 
 * @param parent The pointer to the parent frame
 * @param row The row number where the element locates
 * @param column The column number where the element locates
 * @param leaf The pointer to the leaf widget to be placed
 * @return fwWidget* The pointer to the original widget at this place
 */
fwWidget* fwSetWidgetAs(fwFrame* parent,
							 int row, int column,
							 fwWidget* widget);

void fwUpdate(fwMainFrame* mainFrame);

/**
 * @brief Locate the leaf widget which contains which the point is inside
 * 
 * @param frame The pointer to the frame which contains the point
 * @param xpos The point x-coordinate, relative to the left edge of
 *   the content area.
 * @param ypos The point y-coordinate, relative to the left edge of
 *   the content area.
 * @return fwLeafWidget* The pointer of the located leaf widget,
 *   nullptr if not found
 */
fwLeafWidget* fwLocateLeafWidget(fwFrame* frame, int xpos, int ypos);

}

#endif // FRAME_WINDOW_H
