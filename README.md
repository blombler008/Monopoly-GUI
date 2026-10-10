# Monopoly GUI

A lightweight LVGL-based graphical UI library for the ESP32 Monopoly project. This repository contains the generated and editable GUI files used to render the game screens, settings panels, and interactive components for the Monopoly board game experience.

## Overview

This project provides the visual front end for the Monopoly game running on an ESP32 microcontroller. It is built around LVGL and designed to work with a 320x240 display, with reusable components for menus, settings, player setup, and gameplay interactions.

The repository is structured as an Arduino/PlatformIO library and includes:

- LVGL UI definitions and generated C/C++ code
- Screen and component XML files for editing in LVGL Pro Editor
- Fonts and image assets
- Library metadata for Arduino and PlatformIO integration
- Pre-generated code that can be compiled into the main Monopoly firmware

## Features

- LVGL-based interface for ESP32 hardware
- Game welcome screen and startup flow
- Settings screens for players, game rules, audio, and connectivity
- RFID-related card setup UI
- Reusable basic widgets and specialized card components
- Support for generated UI code from LVGL editor definitions
- PlatformIO and Arduino IDE compatibility

## Repository structure

```text
Monopoly-GUI/
├── LICENSE
├── README.md
├── library.json
├── library.properties
├── src/
│   ├── CMakeLists.txt
│   ├── Monopoly.h
│   ├── Monopoly.c
│   ├── Monopoly_gen.h
│   ├── Monopoly_gen.c
│   ├── globals.xml
│   ├── languages.xml
│   ├── project.xml
│   ├── components/
│   │   ├── README.md
│   │   ├── basic/
│   │   └── cards/
│   ├── screens/
│   ├── fonts/
│   │   └── README.md
│   ├── images/
│   ├── preview-bin/
│   └── preview-build/
├── .gitignore
├── .gitattributes
└── .gitmodules
```

## Requirements

### Software

- LVGL 9.4.x
- ESP32 Arduino core
- PlatformIO or Arduino IDE
- CMake for regenerating generated source from XML files

### Hardware

- ESP32 microcontroller
- TFT display, commonly 320x240 RGB565
- Compatible display driver stack

## Important compatibility note

This library is built specifically for LVGL 9.4. It is not intended for newer or older LVGL versions without checking API compatibility.

## Installation

### PlatformIO

Add this library as a dependency in your project:

```ini
lib_deps =
    lvgl/lvgl@9.4.0
    https://github.com/blombler008/Monopoly_GUI
```

### Arduino IDE

1. Clone the repo or download it.
2. Copy it into your Arduino libraries folder.
3. Restart the IDE and include it in your project.

## Build and generation flow

This project can be used in one of two ways:

### Standard workflow

The repository already contains generated UI code, so most users only need to compile the main project.

```bash
platformio run -e release
```

### Regenerate GUI code

If you edit the LVGL XML project files and want to regenerate the C/C++ source code:

```bash
cd src
cmake -B build
cmake --build build
```

This updates generated files such as `*_gen.c` and `*_gen.h` from the XML definitions.

## Integration with the Monopoly project

This UI library is intended to be used with the main ESP32 Monopoly firmware. Together, they provide a full embedded game experience with:

- menu and setup screens
- player configuration
- game rules and settings
- RFID card registration
- hardware-driven UI rendering on an ESP32 display

## Development workflow

The GUI is designed to be edited visually in LVGL Pro Editor using the XML files in `src/`, then regenerated with CMake before being compiled into the final firmware.

Typical workflow:

1. Open `src/project.xml` in LVGL Pro Editor.
2. Modify screens or components visually.
3. Regenerate GUI code with CMake.
4. Build the project with PlatformIO.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Links

- Main project: https://github.com/blombler008/Monopoly
- LVGL: https://lvgl.io
- LVGL Pro Editor: https://lvgl.io/pro
- Arduino ESP32: https://github.com/espressif/arduino-esp32

## Notes

This repository is still active development and is primarily focused on producing the game interface for the larger Monopoly hardware project.
