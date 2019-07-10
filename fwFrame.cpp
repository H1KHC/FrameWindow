#if defined(WIN32) || defined(WIN64)
#include <Windows.h>
#endif
#include <GL/gl.h>

#include "fwFrame.h"
#include "fwMainFrame.h"

void fwFrame::onRepaint()
{
	for (auto& Column : m_elements) {
		for (fwWidget* element : Column) {
			bool isLeaf = (element->type() == WidgetType::LeafWidget);
			
			if (isLeaf) {
				glPushMatrix();

				// Coordinate system transform
				//   from window system(originated from up-left)
				//   to opengl system(origionated from bottom-left)
				glTranslatef((GLfloat)element->getWidgetXPos(),
					getOwner()->getWindowHeight() -
						(GLfloat)element->getWidgetYPos() -
						element->getWidgetHeight(), 0);
			}

			element->onRepaint();

			if (isLeaf) {
				glPopMatrix();
			}
		}
	}
}
