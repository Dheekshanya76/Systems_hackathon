# Chronicle – Ironhold World Engine

Chronicle is the backend world-state engine for **Ironhold**, an open-world survival game. It is developed incrementally through milestones, adding new functionality while maintaining compatibility with previous features.

## Milestone 1 – Debug Console

Implemented an interactive developer console with the following features:

- Interactive REPL with `ironhold>` prompt
- Meta commands:
  - `.help`
  - `.version`
  - `.status`
  - `.quit`
- Unknown command handling
- World command stub for non-dot commands

---

## Milestone 2 – Entity Commands and World State

This milestone introduces the first in-memory world state by supporting **Player** entities.

### Features

- SPAWN PLAYER command
- LIST PLAYERS command
- In-memory player storage
- Duplicate Player ID detection
- Username validation (maximum 32 characters)
- Email validation (maximum 255 characters)
- Syntax error handling for malformed commands
- Sorted player listing by ID
- Support for command-line world file argument (reserved for future persistence)

---

## Supported Commands

### Meta Commands

| Command | Description |
|---------|-------------|
| `.help` | Show available commands |
| `.version` | Display engine version |
| `.status` | Display current world status |
| `.quit` | Exit the application |

### World Commands

Spawn a player

```text
SPAWN PLAYER <id> <username> <email>
```

Example

```text
SPAWN PLAYER 1 alice alice@ironhold.gg
```

List all players

```text
LIST PLAYERS
```

---

## Example Session

```text
ironhold> SPAWN PLAYER 1 alice alice@ironhold.gg
Spawned.

ironhold> SPAWN PLAYER 2 bob bob@ironhold.gg
Spawned.

ironhold> LIST PLAYERS
[1] alice <alice@ironhold.gg>
[2] bob <bob@ironhold.gg>
2 entities.

ironhold> .quit
```

---

## Project Structure

```
chronicle/
├── include/
│   ├── player.hpp
│   ├── command.hpp
│   ├── world_state.hpp
│   └── application_state.hpp
├── src/
│   ├── main.cpp
│   ├── command.cpp
│   └── world_state.cpp
├── tests/
├── Makefile
└── README.md
```

---

## Build

Compile the project using:

```bash
make
```

Run the application:

```bash
./chronicle
```

Clean generated files:

```bash
make clean
```

---

## Current Status

-  Milestone 1 Complete
-  Milestone 2 Complete
