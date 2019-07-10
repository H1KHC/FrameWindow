## Frame Window

Frame Window is a C++ library that helps organize widgets in GLFW.

~~And it is much similar to the OpenWS~~


### Dependences

This library is heavily dependent on glfw, which means even you don't need
 glfw to compile this library, you still need it when compiling your program
 when using it.

### Build

1. `cd` into the library's directory
2. `mkdir .build` to create a build directory, in order to separate
 the generated files and the sources
3. `cd .build && cmake ..` to generate makefile
4. `make` to make all the stuffs we need


### Tutorial

There is a complete example located in `example/test.cpp` if you need.

This library is organized as a tree structure, with frames stand for
 all the non-leaf nodes and user-defined widget for all the leaf nodes.

So in order to make it work, you need to:
- Implement a widget inheriting `fwLeafWidget`, with all the callbacks you need
    and a display function
- Setup a glfw window
- Initialize Main Frame Window from glfwWindow by calling `fwInitFrameWindow`
- Initialize each element inside by calling `fwInitWidgetAs*`, making sure
    every node is initialized
- Run glfw-style mainloop, and call `fwUpdate` each time window repaint is
    needed

#### Firstly, Implement a widget

This library works in C++, so it is much easier to implement a widget than in C.

By implementing a class as a fwLeafWidget

A simple window class is like this:

```cpp
class Rect : public public fwLeafWidget {
public:
    virtual void onRepaint() {
        glColor3f(1.0f, 0.0f, 0.0f);
        glRecti(0, 0, 64, 64);
    }
}
```

For the purpose of representation, there is a fully implemented class with all
 the available callbacks implemented in the `example/test.cpp`

#### Secondly, setup glfw window

As the Frame is based on glfw, it is of course the first thing to setup the
 glfw window.

In this instance, we created a non-resizable window whose width is 416px,
 height is 64px and title is "test".

```cpp
glfwInit();
glfwWindowHint(GLFW_RESIZABLE, false);
GLFWwindow* window = glfwCreateWindow(128, 64, "test", nullptr, nullptr);
```

#### Thirdly, initialize Main Frame Window from glfwWindow

fwInitFrameWindow creates a MainFrame which binds to the glfwWindow, and
 the following parameters.

Here our MainFrame is a 1x3 form. The width of each column is 192px, 192px
 and 32px respectively, and the height is 64px. 

```cpp
fwMainFrame* mainFrame = fwInitFrameWindow(window, 1, 3, { 192, 192, 32 }, { 64 });
```

#### Fourthly, initialize each element inside the Main Frame

By calling fwInitWidgetAs*, you can init each element as either a leaf
 or a subframe.

> Attaintion: As by now I have no idea how to handle out-of-bound element
 access, the program will crash if you access an element outside the frame

Here we initialized the left two elements as leaves, and the rightside one as
 a 2x1 subform containing two leaves.

 ```cpp
fwSetWidgetAsLeaf(mainFrame, 0, 0, &block[0]);
fwSetWidgetAsLeaf(mainFrame, 0, 1, &block[1]);
fwFrame* subFrame = fwInitWidgetAsFrame(mainFrame, 0, 2, 2, 1,
                                            { 32 }, { 32, 32 });
fwSetWidgetAsLeaf(subFrame, 0, 0, &block[2]);
fwSetWidgetAsLeaf(subFrame, 1, 0, &block[3]);
 ```

#### Finally, run glfw main loop

I implemented a function fwUpdate, so the mainloop is handed over to the user,
rather than the library.

This mainloop is similar to the one we use in common glfw programs, although
 you need to call fwUpdate each time you want to repaint the window.

By the way, you don't need to call glfwMakeContextCurrent each time, as I
 will check the context in fwUpdate.

```cpp
while(!glfwWindowShouldClose(window)) {
    fwUpdate(mainFrame);
    glfwPollEvents();
}
```
