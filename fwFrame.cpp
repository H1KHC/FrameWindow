#if defined(WIN32) || defined(WIN64)
#include <Windows.h>
#endif
#include <GL/gl.h>

#include "fwFrame.h"

void fwFrame::display()
{
	for (auto& Column : elements) {
		for (fwWidget* element : Column) {
			bool isLeaf = (element->type() == WidgetType::LeafWidget);
			
			if (isLeaf) {
				glPushMatrix();
				glTranslatef((GLfloat)element->pos[0], (GLfloat)element->pos[1], 0);
			}

			element->display();

			if (isLeaf) {
				glPopMatrix();
			}
		}
	}
}
