#pragma once
#include "fwWidget.h"
#include "fwFrame.h"
class fwLeafWidget :
	public fwWidget
{
protected:
	fwLeafWidget()/* Nullptr-fy callbacks */ {}
	
	friend class fwMainFrame;

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4100)
#endif
	virtual void mouseEnterCallback(bool enter) { }
	virtual void focusCallback(bool focus) { }
	virtual void mouseButtonCallback(int button, int action, int mods) { }
	virtual void scrollCallback(double xoffset, double yoffset) { }
	virtual void fileDropCallback(int path_count, const char* paths[]) { }
	virtual void keyCallback(int key, int scancode, int action, int mods) { }
	virtual void charModsCallback(unsigned int codepoint, int mods) { }
#ifdef _MSC_VER
#pragma warning(pop)
#endif
public:
	WidgetType type() const override {
		return WidgetType::LeafWidget;
	}

	bool available() { return parent != nullptr; }
};

