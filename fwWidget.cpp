#include "fwWidget.h"
#include "fwFrame.h"

void fwWidget::attachTo(fwFrame* frame, int row, int column)
{
	parent = frame;
	depth = frame->depth + 1;
	pos[0] = frame->getXPos(column);
	pos[1] = frame->getYPos(row);
	size[0] = frame->getWidth(column);
	size[1] = frame->getHeight(row);
}
