# Changelog {#Changelog}
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## Unreleased

## 0.0.2
### Added
- [ `fw*` ] `get*()` and `set*()` to get and set member variables
- [ `global` ] `fwSetWidgetAs` to replace `fwInitWidgetAsLeaf`
- [ `fwLeafWidget` ] `cursorMoveCallback()` to handle cursor move event
- [ `fwWidget` ] `m_owner` to trace the mainFrame current widget belongs to
- [ `fwWidget` ] `owner()` to get that mainFrame
- virtual destructor for each class
- doxygen configuration, as well as document in code

### Changed
- Merged file `fwCallbacks.h` into `fwMainWindow.h`
- [ `fwFrame` / `fwMainFrame` ] Include `fwFrame.h` and `fwMainFrame.h` in FrameWindow
- [ `fw*` ] Member variable access property from `protected` to `private`
- [ `fw*` ] Added prefix 'm_' for all the member variables
- Function rename:
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
-  [ `fw*` ] Re-sorted the members' initialization in the constructors
- [ `example` ] Added `fflush` after each `printf`

### Fixed
- m_owner of fwMainFrame is nullptr, which causes crash in fwUpdate
- Subframe location upside-down

### Removed
- [ `global` ] `fwInitElementAsLeaf`

## 0.0.1 / 2019-07-07
### Added
- CHANGELOG file
