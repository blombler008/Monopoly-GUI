# Monopoly GUI Library

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform: ESP32](https://img.shields.io/badge/Platform-ESP32-brightgreen.svg)](https://www.espressif.com/en/products/socs/esp32)
[![Framework: Arduino](https://img.shields.io/badge/Framework-Arduino-blue.svg)](https://www.arduino.cc/)

A comprehensive graphical user interface library for the Monopoly board game running on ESP32 microcontrollers, powered by the **LVGL (Light and Versatile Graphics Library)**.

## Overview

The Monopoly GUI library provides a complete, production-ready user interface for a Monopoly game application. It features an intuitive design system built with LVGL, pre-designed screens for game flow, customizable components for game settings, and support for a 320x240 RGB565 display.

## Features

- **Complete Game Interface**: Pre-built screens for welcome, game start, settings, card management, and more
- **Modular Component System**: Reusable UI components organized as basic widgets and specialized cards
- **Advanced Input Controls**: Spin boxes and spin labels for numerical adjustments (player count, starting cash)
- **LVGL Integration**: Optimized for LVGL graphics library with Material Design-inspired theming
- **Flexible Configuration**: Global settings, color schemes, and responsive design layouts
- **Multi-language Support**: Language configuration framework in `languages.xml`
- **Device Settings Panels**: Audio, connectivity, game, and player configuration cards
- **Theme System**: Dark/light themes with accent colors and visual hierarchy
- **Relative Path Build System**: Editor preview support and flexible build configuration
- **Arduino IDE Compatible**: Built as an Arduino library for seamless PlatformIO/Arduino IDE integration

## Requirements

### Hardware

- **Microcontroller**: ESP32 (with minimum 320KB RAM for GUI rendering)
- **Display**: 320x240 RGB565 LCD display (8-bit parallel, SPI, or I2C interface)
- **Memory**: Minimum 4MB flash recommended for assets and fonts

### Software Dependencies

- **LVGL**: Light and Versatile Graphics Library (v9.4 **REQUIRED** - NOT compatible with v9.5 or v9.2 and below)
- **Arduino ESP32 Core**: For ESP32 board support
- **CMake**: For GUI build system (3.13 or higher)
- **PlatformIO**: Handles compilation of the complete project after GUI compilation

## Installation

### Method 1: PlatformIO (Recommended)

1. Add to your `platformio.ini`:

```ini
lib_deps =
    https://github.com/blombler008/Monopoly_GUI
```

1. The library will be automatically downloaded and linked during compilation.

### Method 2: Arduino IDE

1. Download or clone the repository
2. Place in your Arduino `libraries` folder:
   - Linux/Mac: `~/Arduino/libraries/`
   - Windows: `Documents\Arduino\libraries\`
3. Restart Arduino IDE

### Method 3: Manual

```bash
cd your_project/lib
git clone https://github.com/blombler008/Monopoly_GUI.git
```

## Build System

⚠️ **The Monopoly GUI is typically pre-compiled** with all C/H code already generated. In most cases, you only need to use **PlatformIO** to compile your project. Follow **Stage 2** below.

However, if you need to regenerate GUI code (e.g., after editing with LVGL SquareLine Studio), follow **Stage 1** first.

### Stage 1: GUI Code Generation (CMake) - *Optional/Advanced*

**Only needed if regenerating GUI code from XML definitions**
The GUI code generation uses **CMake** to generate C and H source files from LVGL XML definitions:

```bash
cd Monopoly_GUI/src
cmake -B build
cmake --build build
```

CMake generates:

- `Monopoly_gen.c` and `Monopoly_gen.h` - Generated LVGL component code
- Component-specific generated files (`*_gen.c`, `*_gen.h`) - Individual screen and component code
- Embedded assets (fonts, images) - Pre-compiled into binary format
- Build artifacts for LVGL SquareLine Studio preview

**Note**: This code generation step is only needed when you modify the GUI using LVGL SquareLine Studio and want to regenerate the source code.

### Stage 2: Project Compilation (PlatformIO) - *Standard Workflow*

**This is the typical build process for end users**
Compile your project with PlatformIO using the pre-generated GUI code:

```bash
platformio run --target upload --environment release
```

PlatformIO automatically:

- Compiles the pre-generated GUI C code
- Compiles your main application code
- Links all dependencies
- Manages the ESP32 build configuration

This is the standard workflow:

- Pre-compiled GUI code is already in the repository
- PlatformIO handles all compilation and linking
- Fast and straightforward builds
- No need to run CMake manually

## Quick Start

### Basic Integration

```cpp
#include "Monopoly.h"

void setup() {
    // Initialize LVGL first (before Monopoly)
    lv_init();
    
    // Initialize display driver (depends on your display connection)
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, MY_DISP_HOR_RES * 10);
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &draw_buf;
    disp_drv.hor_res = 320;
    disp_drv.ver_res = 240;
    lv_disp_drv_register(&disp_drv);
    
    // Initialize the Monopoly GUI library
    Monopoly_init("./assets/");  // Path to assets (fonts, images)
}

void loop() {
    lv_timer_handler();
    delay(5);
}
```

### Display Configuration

The library is optimized for:

- **Resolution**: 320x240 pixels
- **Color Format**: RGB565 (16-bit)
- **Refresh Rate**: 30-60 Hz recommended

## Project Structure

```txt
Monopoly_GUI/
├── src/
│   ├── Monopoly.h                 # Main library header
│   ├── Monopoly.c                 # Core implementation
│   ├── Monopoly_gen.h/c           # Generated GUI code (LVGL Editor)
│   ├── CMakeLists.txt             # Build configuration
│   ├── project.xml                # LVGL Editor project definition
│   ├── globals.xml                # Global styles, colors, constants
│   ├── languages.xml              # Multi-language support
│   │
│   ├── screens/                   # Game screens
│   │   ├── welcome/               # Welcome/splash screen
│   │   ├── game_start/            # Game initialization screen
│   │   ├── settings/              # Settings menu
│   │   ├── add_card/              # RFID card registration
│   │   └── about/                 # About screen
│   │
│   ├── components/                # Reusable UI components
│   │   ├── basic/                 # Fundamental components
│   │   │   ├── button/            # Custom button component
│   │   │   ├── label/             # Text labels
│   │   │   ├── card/              # Card containers
│   │   │   ├── header/            # Header bars
│   │   │   ├── row/               # Horizontal layout
│   │   │   ├── column/            # Vertical layout
│   │   │   ├── div/               # Generic container
│   │   │   ├── content/           # Content container
│   │   │   ├── spinner/           # Loading spinner
│   │   │   ├── timehead/          # Time display header
│   │   │   ├── spin_label/        # Numerical input with buttons
│   │   │   └── spin_box/          # Flexible spin box for numbers
│   │   └── cards/                 # Specialized setting cards
│   │       ├── playerSettingsCard/   # Player configuration
│   │       ├── gameSettingsCard/     # Game rules settings (includes player count row)
│   │       ├── audioSettingsCard/    # Audio preferences
│   │       └── connectionSettingsCard/ # Network settings
│   │
│   ├── fonts/                     # Pre-integrated fonts
│   │   ├── Roboto_16              # 16px font
│   │   ├── Roboto_24              # 24px font
│   │   ├── RobotoB_16             # 16px bold font
│   │   └── RobotoB_24             # 24px bold font
│   │
│   ├── images/                    # Image assets
│   ├── preview-bin/               # LVGL Editor preview runtime (WASM)
│   └── preview-build/             # Build artifacts for editor
│
├── library.json                   # PlatformIO library metadata
├── library.properties             # Arduino IDE library metadata
└── LICENSE                        # MIT License
```

## Configuration

### Global Settings (globals.xml)

The library provides configurable global settings for styling and game parameters:

**Spacing Units**:

```xml
<int name="unit_sm" value="6" />    <!-- 6px -->
<int name="unit_md" value="12" />   <!-- 12px -->
<int name="unit_lg" value="18" />   <!-- 18px -->
<int name="unit_xl" value="24" />   <!-- 24px -->
```

**Color Scheme** (Dark/Light theme support):

```xml
<!-- Primary surface -->
<color name="surface_primary_dark" value="0xffffff" />
<color name="text_on_surface_primary_dark" value="0x0e0e0e" />

<!-- Backgrounds -->
<color name="bg_primary_dark" value="0x0e0e0e" />
<color name="bg_secondary_dark" value="0x373130" />

<!-- Accent colors -->
<color name="accent1_dark" value="0xAF4ADE" />  <!-- Purple primary -->
<color name="accent2_dark" value="0x887A3D" />  <!-- Gold secondary -->
```

**Game Parameters** (Subject bindings):

```xml
<int name="start_cash" min_value="0" max_value="500000" value="1500" />
<int name="player_count" min_value="0" max_value="8" value="0" />
<int name="bluetooth_on" min_value="0" max_value="1" value="0" />
<int name="wifi_on" min_value="0" max_value="1" value="0" />
<int name="nfc_on" min_value="0" max_value="1" value="0" />
<int name="battery_level" min_value="0" max_value="100" value="50" />
```

## Screens

### 1. Welcome Screen (`screens/welcome/`)

- **Purpose**: Splash screen and game overview
- **Resolution**: 320x240
- **Usage**: Initial app launch screen

### 2. Game Start Screen (`screens/game_start/`)

- **Purpose**: Main game action interface with interactive tiles
- **Features**: Tile-based action buttons for:
  - Transactions (player-to-player money transfers)
  - Pass Go (move to Go and collect $200)
  - Property management actions
  - Other board actions and special events
- **Note**: All game settings are configured in the **Settings Menu** before starting a game. Version 2.0 will include in-game setting adjustments.

### 3. Settings Screen (`screens/settings/`)

- **Purpose**: Pre-game configuration and player setup (before game start)
- **Contains**:
  - Player Settings Card (names, colors, tokens)
  - Game Settings Card (starting cash, player count, house rules)
  - Audio Settings Card (volume, sound preferences)
  - Connection Settings Card (Wi-Fi, Bluetooth, NFC)
- **When Used**: All game parameters must be configured here before starting a game

### 4. Add Card Screen (`screens/add_card/`)

- **Purpose**: RFID card registration and player association
- **Integration**: Works with RFID module for player identification
- **Usage**: Associates player profiles with RFID cards for authentication

### 5. About Screen (`screens/about/`)

- **Purpose**: Application information and credits

## Game Workflow

**Pre-Game Setup** → Game Start

1. User opens the app to Welcome Screen
2. Navigates to Settings Screen to configure:
   - Player names, colors, and tokens
   - Starting cash amount
   - Player count (2-8 players)
   - Audio and connection preferences
3. Associates player RFID cards in Add Card Screen
4. Returns to Welcome Screen and starts game

**During Game** → Game Start Screen

- Interactive tiles display available game actions
- Players can execute transactions, navigate board, manage properties
- Limited settings adjustments available (version 2.0 feature)
- All gameplay actions managed through the tile-based interface

**Future** → Version 2.0

- In-game setting adjustments will be added alongside the action tiles

## Components

### Basic Components (`components/basic/`)

These are the foundation building blocks for all screens:

- **Button**: Clickable button with visual feedback
- **Label**: Text display with font and color customization
- **Card**: Container for content with depth/shadow effects
- **Header**: Top navigation and title bar
- **Row**: Horizontal flex container
- **Column**: Vertical flex container
- **Div**: Generic container for grouping
- **Content**: Specialized content wrapper
- **Spinner**: Loading indicator animation
- **TimeHead**: Time and status display header
- **Spin Label**: Numerical input with increment/decrement buttons (for player count, starting cash, etc.)
- **Spin Box**: Flexible spin box component for numerical adjustments with dynamic properties

### Specialized Cards (`components/cards/`)

Domain-specific UI components for game settings:

- **Player Settings Card**: Player name, color, and token selection
- **Game Settings Card**: Money limitations, house rules, game rules, player count adjustment
- **Audio Settings Card**: Volume, sound effects, music toggles
- **Connection Settings Card**: Wi-Fi, Bluetooth, NFC configuration

## Input Control Components (NEW)

### Spin Label & Spin Box

The latest development includes advanced numerical input controls for enhanced game configuration:

- **Spin Label**: Provides a clean interface for numerical input with dedicated increment/decrement buttons
  - Used for: Player count adjustment, starting cash configuration
  - Features: Dynamic buttons, customizable min/max values, visual feedback
  - Integration: Already integrated into Game Settings Card

- **Spin Box**: A flexible component system for any numerical adjustment
  - Features: Dynamic properties, reusable architecture, animation support
  - Extended from basic components for wide compatibility
  - Can be adapted for additional settings or custom implementations

These components provide an intuitive way for players to adjust game parameters directly from the settings interface.

## Recent Changes (v1.0.0)

### Latest Commits: Input Control Enhancements & Player Count Integration

- **Date**: February 15, 2026
- **Recent Changes**:
  - Added **player count row** to game settings card for easy player configuration
  - Implemented **spin_label** component with increment/decrement buttons for numerical input
  - Created **spin_box** component with dynamic properties for flexible numerical adjustments
  - Refactored spin box implementation for improved usability and reusability
  - Added **light color definition** to globals.xml for enhanced theming
  - Reorganized spin box component file structure for better organization
  - Enhanced dynamic properties system for improved component flexibility

### Previous Milestone: Build System Refactor

- **Date**: February 13, 2026
- **Changes**:
  - Converted CMakeLists.txt to generated file format
  - Adapted build system for LVGL Editor preview compatibility
  - Introduced `LIB_NAME` and `LV_EDITOR_COMPONENT_LIB_LIST` variables
  - Updated component includes to use relative paths
  - Refreshed embedded font binaries
  - Added src/.gitignore for preview-build artifacts
  - Updated CMake configuration for improved build flexibility

### Build System Improvements

- **Relative Path Support**: Components now use relative paths to `Monopoly.h`
- **Editor Integration**: Full compatibility with LVGL SquareLine Studio editor
- **Flexible Include System**: Supports both library and project-level builds
- **Artifact Management**: Automated cleanup of preview artifacts
- **Input Control Integration**: Spin controls integrated into game settings for dynamic player configuration

## Development & Customization

### Editing with LVGL SquareLine Studio (Advanced)

**Only if you need to modify the GUI design:**

The library is fully compatible with LVGL SquareLine Studio (formerly LVGL Editor):

1. Open `src/project.xml` in SquareLine Studio
2. Edit screens and components visually
3. Export/generate the project (Studio creates/updates XML files in `src/`)
4. **Generate GUI code with CMake**: `cd src && cmake -B build && cmake --build build`
5. CMake generates all `.c` and `.h` files from the XML definitions
6. Commit the generated C/H files (`*_gen.c`, `*_gen.h`)
7. PlatformIO will compile the regenerated GUI code when building the main project

Generated C/H files (`*_gen.c`, `*_gen.h`) are created by CMake and should not be manually edited.
Edit the XML files instead, then regenerate the C/H code with CMake.

### Extending the GUI (Advanced)

**Only if you need to add screens or components:**

1. **Add New Screen**:
   - Create directory: `src/screens/your_screen/`
   - Add XML definition in SquareLine Studio or manually create XML
   - Reference in `src/project.xml`
   - Regenerate C/H code: `cd src && cmake -B build && cmake --build build`

2. **Add Custom Component**:
   - Create directory: `src/components/[basic|cards]/your_component/`
   - Define XML component file in SquareLine Studio
   - Implement custom callbacks in generated C files if needed
   - Regenerate: `cd src && cmake -B build && cmake --build build`

3. **Modify Coors/Styles**:l
   - Edit `src/globals.xml`
   - Update color values in the `<consts>` section
   - Regenerate C/H code with CMake to apply changes

**Important**: After any XML changes, always regenerate the C and H code files with CMake before committing and building with PlatformIO.

For most users working with standard gameplay, GUI extensions are not necessary.

### Build Configuration (Advanced)

**Only if you need to customize CMAKE code generation:**

The GUI's CMake configuration is defined in `src/CMakeLists.txt`. This file controls how CMake generates the C and H code files. Edit it to:

- Configure LVGL settings used during code generation
- Add custom include directories for GUI code generation
- Link additional LVGL modules or plugins
- Define GUI-specific build flags
- Customize the LVGL Editor preview build

After modifying CMakeLists.txt, regenerate the GUI code:

```bash
cd src
cmake -B build --fresh
cmake --build build
```

This regenerates all `.c` and `.h` files based on the updated configuration. Once complete, PlatformIO automatically compiles the updated GUI code.

For standard use cases, the default CMakeLists.txt configuration is already optimized.

## API Reference

### Core Functions

```cpp
/**
 * Initialize the Monopoly GUI library
 * @param asset_path Path to assets directory (fonts, images)
 */
void Monopoly_init(const char * asset_path);
```

All generated GUI code is accessed through LVGL API functions. Refer to [LVGL Documentation](https://docs.lvgl.io/) for screen, widget, and event handling API.

## Integration with Monopoly Project

This library is designed to integrate with the main Monopoly game application:

- **RFID Module**: Works with MFRC522 RFID reader for player card management
- **Main Microcontroller**: Coordinate with core game logic
- **Data Persistence**: Settings stored in ESP32 NVS (Non-Volatile Storage)
- **Power Management**: Display and component optimization for battery operation

## Troubleshooting

### Critical: LVGL Version Compatibility

⚠️ **This library is built for LVGL v9.4 only** and will NOT work with other versions:

- **LVGL v9.5**: Incompatible - Breaking changes in LVGL API
- **LVGL v9.2 and below**: Incompatible - Missing required features
- **LVGL v9.4**: ✅ Supported - Use this version only

If you encounter compilation errors or runtime issues, verify your LVGL version:

```cpp
// Check LVGL version
#include "lvgl.h"
// LVGL_VERSION_MAJOR should be 9, LVGL_VERSION_MINOR should be 4
```

In PlatformIO, specify the exact version in `platformio.ini`:

```ini
lib_deps =
    lvgl/lvgl@9.4.0
    https://github.com/blombler008/Monopoly_GUI
```

### Build Issues

**GUI Code Generation (CMake)**:

- **`Cannot find LVGL`**: Ensure LVGL v9.4 is installed and CMake can find it
- **CMake errors**: Run `cmake -B build --fresh` to regenerate from scratch
- **Generated C/H files missing**: Run `cmake --build build` to generate `*_gen.c` and `*_gen.h` files from XML definitions
- **XML parsing errors**: Check `src/project.xml` and component XML files for syntax errors
- **Build directory issues**: Clear with `rm -rf src/build` (or `rmdir /s src\build` on Windows) and retry

**Project Compilation (PlatformIO)**:

- **`Cannot find Monopoly.h` or `Monopoly_gen.h`**: Ensure CMake code generation completed first; check that generated files exist in `src/`
- **LVGL version errors**: Verify LVGL v9.4 is specified in platformio.ini
- **Link errors**: Confirm all CMake-generated C/H files are present in `src/`
- **Font rendering issues**: Check font files exist in `src/fonts/` and regenerate with CMake after adding fonts

### Display Issues

- **GUI not appearing**: Verify LVGL initialization before `Monopoly_init()`
- **Colors incorrect**: Check RGB565 format. Value `0xFFFF` = white, `0x0000` = black
- **Performance issues**: Increase frame rate, enable hardware acceleration

### Editor Preview

- **Preview not loading**: Ensure Node.js and correct LVGL version
- **Build.log errors**: Check `src/preview-build/CMakeFiles/` for details
- **WASM issues**: Clear `src/preview-bin/` cache and rebuild

## Contributing

Contributions are welcome! Please:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/your-feature`)
3. Test thoroughly on ESP32 hardware
4. Submit a pull request with clear description
5. Follow existing code style and structure

## Performance Tips

- **Reduce Update Frequency**: Call `lv_timer_handler()` at 30Hz instead of 60Hz for battery savings
- **Asset Optimization**: Use compressed image formats when possible
- **Font Selection**: Limit active fonts (currently 4 fonts integrated)
- **Memory Management**: Monitor free heap space with `esp_get_free_heap_size()`

## Known Limitations

- Currently optimized for 320x240 displays only
- Limited to 8 players maximum (set in globals.xml)
- Requires approximately 500KB flash for GUI assets

## Future Enhancements

- [ ] Support for higher resolution displays (480x320, 800x480)
- [ ] Dynamic theme switching at runtime
- [ ] Touch gesture support
- [ ] Animation transitions between screens
- [ ] Widget accessibility improvements
- [ ] Hardware acceleration for rendering

## License

This project is licensed under the **MIT License** - see the LICENSE file for details.

Copyright © 2025 blombler008

## References

- [LVGL Documentation](https://docs.lvgl.io/)
- [LVGL SquareLine Studio](https://www.lvgl.io/tools/squareline-studio)
- [Arduino ESP32 Core](https://github.com/espressif/arduino-esp32)
- [Monopoly Project Repository](https://github.com/blombler008/Monopoly_GUI)

## Author

**blombler008** - Main developer and maintainer

For issues, questions, or suggestions, please open an issue on GitHub.

---

**Last Updated**: February 15, 2026  
**Version**: 1.0.0  
**Status**: Active Development  
**Latest Commit**: Add player count row to game settings card (609204142d2346948ef0d6b98919f36e3572a95e)
