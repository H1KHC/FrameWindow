#include "fwWidget.h"
#include "fwFrame.h"

void fwWidget::attachTo(fwFrame* frame, int row, int column)
{
	m_parent = frame;
	m_owner = frame->m_owner;
	m_depth = frame->m_depth + 1;
	m_pos[0] = frame->getColumnXPos(column);
	m_pos[1] = frame->getRowYPos(row);
	m_size[0] = frame->getColumnWidth(column);
	m_size[1] = frame->getRowHeight(row);
}
