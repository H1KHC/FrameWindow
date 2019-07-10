# Changelog {#Changelog}
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## Unreleased
### Added
- [ `fwLeafWidget` ] `cursorMoveCallback()` to handle cursor move event
- [ `fwWidget` ] `m_owner` to trace the mainFrame current widget belongs to
- [ `fwWidget` ] `owner()` to get that mainFrame
- [ `fwMainFrame` ] `getGLFWWindow()` to get the GLFWwindow
- [ `fwMainFrame` ] `getWindowXPos()`
- [ `fwMainFrame` ] `getWindowYPos()`
- [ `fwMainFrame` ] `getWindowWidth()`
- [ `fwMainFrame` ] `getWindowHeight()`
- virtual destructor for each class

### Changed
- Merged file `fwCallbacks.h` into `fwMainWindow.h`
- Expose `fwFrame` and `fwMainFrame`
- Member variable access property from `protected` to `private`
- Added `get*()` and `set*()` in each class to get and set member variables
- Added prefix 'm_' before all member variables
- Function rename:
    - [ `global` ] `fwInitWidgetAsLeaf` -> `fwSetWidgetAsLeaf`
    - [ `fwFrame` ] `getXPos` -> `getColumnXPos`
    - [ `fwFrame` ] `getYPos` -> `getRowYPos`
    - [ `fwFrame` ] `getWidth` -> `getColumnWidth`
    - [ `fwFrame` ] `getHeight` -> `getRowHeight`
    - [ `fwLeafWidget` / `fwMainFrame` ] `mouseEnterCallback` -> `onCursorEnter`
    - [ `fwLeafWidget` / `fwMainFrame` ] `windowPositionCallback` -> `onWindowMove`
    - [ `fwLeafWidget` / `fwMainFrame` ] `windowSizeCallback` -> `onWindowResize`
    - [ `fwLeafWidget` / `fwMainFrame` ] `mouseButtonCallback` -> `onMouseButtonChange`
    - [ `fwLeafWidget` / `fwMainFrame` ] `keyCallback` -> `onKeyChange`
    - [ `fwLeafWidget` / `fwMainFrame` ] `charModsCallback` -> `onInput`
    - [ `fwLeafWidget` / `fwMainFrame` ] `*Callback` -> `On* for all other callbacks`
    - [ `fwWidget` ] `display` -> `onRepaint`
-  Re-sorted the members' initialization in the constructors

### Fixed
- Subframe location upside-down

## 0.0.1 / 2019-07-07
### Added
- CHANGELOG file
