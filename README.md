# QuickHunt

A reaction game made in C++ with SFML 3.1.0.

Enemies come at you in a row. Press the key of the one in front before time runs out: hit the right key and it dies, miss or run out of time and you lose HP. Then the next one steps up. How long can you last?

Made for the SFML bonus jam of Desarrollo de Videojuegos I (Image Campus, 2026).

## How to play

| Key | Enemy |
|---|---|
| `Z` | Square (red) |
| `X` | Triangular (blue) |
| `C` | Round (green) |

- You have **2 seconds** for each enemy.
- A correct key kills the enemy and adds a point.
- A wrong key or a timeout costs **1 HP**, and the enemy leaves anyway.
- You start with **3 HP**.
- There is a short cooldown after each attack, so accidental double presses are ignored.

## Current state

Playable prototype. The core loop works. These are still missing:

- Game over screen and restart
- Time bar
- Sprites, animations and sound
- Menus

## Requirements

- Visual Studio 2026 (toolset v145) with the "Desktop development with C++" workload
- Windows x64

SFML is already included in `lib/`, so there is nothing else to install.

## Project structure

```
├─ bin/       Executables, one folder per configuration (generated on build)
├─ obj/       Intermediate files, one folder per configuration (generated on build)
├─ lib/       External libraries (SFML 3.1.0)
├─ scripts/   Build scripts (post-build copy)
├─ src/       Source code
│  └─ entities/   Player, enemies and the enemy queue
├─ res/       Final assets loaded by the game
└─ res_raw/   Raw/editable assets (.psd, .aseprite, etc.)
```

## Configuration

| | Debug | Release |
|---|---|---|
| Console | Yes | No |
| Warning level | 4, treated as errors | 4, treated as errors |
| C++ standard | C++20 | C++20 |
| SFML libraries | `sfml-*-d.lib` | `sfml-*.lib` |

- `src/` is an include directory, so includes don't need relative paths.
- SFML is linked dynamically. A post-build step (`scripts/copy.bat`) copies `res/` and the matching SFML DLLs into `bin/<Configuration>/`, so the `.exe` runs outside Visual Studio.

## Running a build

The `.exe` needs the SFML DLLs and `res/` next to it. If it doesn't start on a PC without Visual Studio, install the [Microsoft Visual C++ Redistributable](https://learn.microsoft.com/cpp/windows/latest-supported-vc-redist) (x64).

## License

SFML is distributed under the zlib/png license (see `lib/SFML-3.1.0/license.md`).
