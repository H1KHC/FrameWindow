#include <GLFW/glfw3.h>
#include "../FrameWindow.h"


class Block : public fwLeafWidget {
	int ID;
	GLubyte color[4];
protected:
	void onCursorEnter(bool enter) override {
		printf("Block %d: mouseEnterCallback %d\n", ID, enter);
		fflush(stdout);
	}
	void onFocus(bool focus) override {
		printf("Block %d: focusCallback %d\n", ID, focus);
		fflush(stdout);
	}
	void onMouseButtonChange(int button, int action, int mods) override {
		printf("Block %d: mouseButtonCallback %d %d %d\n", ID, button, action, mods);
		fflush(stdout);
	}
	void onScroll(double xoffset, double yoffset) override {
		printf("Block %d: scrollCallback %3lf %3lf\n", ID, xoffset, yoffset);
		fflush(stdout);
	}
	void onFileDrop(int path_count, const char* paths[]) override {
		printf("Block %d: fileDropCallback %d:\n", ID, path_count);
		for (int i = 0; i < path_count; ++i)
			printf("\t- %s\n", paths[i]);
		fflush(stdout);
	}
	void onKeyChange(int key, int scancode, int action, int mods) override {
		printf("Block %d: keyCallback %d %d %d %d\n", ID, key, scancode, action, mods);
		fflush(stdout);
	}
	void onInput(unsigned int codepoint, int mods) override {
		printf("Block %d: charModsCallback %d %d\n", ID, codepoint, mods);
		fflush(stdout);
	}
public:
	void onRepaint() override {
		glColor4ubv(color);
		glRecti(0, 0, getWidgetWidth(), getWidgetHeight());
	}
	Block(int ID, GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) :
		ID(ID), color{ red, green, blue, alpha } { }
};

int main() {
	
	Block block[4] { Block(1, 0xff, 0x00, 0x00, 0xff),
					 Block(2, 0x00, 0xff, 0x00, 0xff),
					 Block(3, 0x00, 0x00, 0xff, 0xff),
					 Block(4, 0xff, 0xff, 0x00, 0xff) };
	glfwInit();
	glfwWindowHint(GLFW_RESIZABLE, false);
	GLFWwindow* window = glfwCreateWindow(416, 64, "test", nullptr, nullptr);
	
	fwMainFrame* mainFrame = new fwMainFrame(window, 1, 3, { 192, 192, 32 }, { 64 });
	fwSetWidgetAs(mainFrame, 0, 0, &block[0]);
	fwSetWidgetAs(mainFrame, 0, 1, &block[1]);
	fwFrame* rightSideFrame = fwInitWidgetAsFrame(mainFrame, 0, 2, 2, 1, { 32 }, { 32, 32 });
	fwSetWidgetAs(rightSideFrame, 0, 0, &block[2]);
	fwSetWidgetAs(rightSideFrame, 1, 0, &block[3]);
	while(!glfwWindowShouldClose(window)) {
		if(glfwGetKey(window, GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(window, true);
		fwUpdate(mainFrame);
		glfwPollEvents();
	}
}