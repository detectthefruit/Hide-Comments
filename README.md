# Hide-Comments
A Geode mod for Geometry Dash that hides level comments written by blocked users.

## Files
- `mod.json` — Geode mod manifest and settings definition
- `src/HideComments.cpp` — mod implementation
- `CMakeLists.txt` — build configuration
- `package.sh` — build and package helper script

## Build & package
1. Install the Geode SDK / CLI and set up the Geometry Dash modding environment.
2. Build the mod:
   ```bash
   mkdir -p build && cd build
   cmake ..
   cmake --build .
   ```
3. Create a `.geode` package:
   ```bash
   cd ..
   ./package.sh
   ```
4. Copy `HideComments.geode` into your Geode mods folder.
5. Launch Geometry Dash and enable the mod in Geode.

## Settings
- `Hide blocked user comments` — toggle hiding of comments authored by blocked users.

## Behavior
- Hooks the Geometry Dash comment cell loading flow.
- Hides comment cells when the author is on your block list.

> Note: Packaging requires the Geode CLI (`geode package new ...`). If build or packaging errors occur, make sure the Geode SDK and CLI are installed and configured for your environment.
