#include <GLFW/glfw3.h>
#include "fwMainFrame.h"

void fwMainFrame::display()
{
	if (glfwGetCurrentContext() != glfwWindow)
		glfwMakeContextCurrent(glfwWindow);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glOrtho(0, size[0], 0, size[1], -1, 1);
	fwFrame::display();
	glfwSwapBuffers(glfwWindow);
}