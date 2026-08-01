
# Chronicle – Ironhold World Engine

Chronicle is the backend world-state engine for **Ironhold**, an open-world survival game.  
The project is developed through milestones, adding features incrementally.

---

# Milestone 1 – Debug Console

Implemented an interactive developer console.

## Features

- REPL interface with `ironhold>` prompt
- Meta commands:
  - `.help`
  - `.version`
  - `.status`
  - `.quit`
- Unknown command handling

---

# Milestone 2 – Entity Commands and World State

Added Player entity management and world commands.

## Features

- `SPAWN PLAYER` command
- `LIST PLAYERS` command
- Player storage and retrieval
- Duplicate ID detection
- Username validation (maximum 32 characters)
- Email validation (maximum 255 characters)
- Syntax error handling
- Sorted player listing by ID

---

# Milestone 3 – Persistent World

Implemented disk persistence using fixed-size binary pages.

## Features

- Binary entity storage
- Fixed-size `PlayerRecord` layout
- Pager-based storage system
- Lazy page loading
- In-memory page caching
- Page flushing on shutdown
- World restoration after server restart

---

# Storage Layout

## Entity Record

Each player entity is stored as a fixed **291-byte** binary record.

| Offset | Size | Field |
|--------|------|-------|
| 0 | 4 bytes | ID (`uint32_t`) |
| 4 | 32 bytes | Username |
| 36 | 255 bytes | Email |

---

## Page Configuration

```

PAGE_SIZE = 4096 bytes
ENTITY_SIZE = 291 bytes
ENTITIES_PER_PAGE = 14
MAX_PAGES = 100
MAX_ENTITIES = 1400

````

---

# Commands

## Meta Commands

| Command | Description |
|---------|-------------|
| `.help` | Show available commands |
| `.version` | Show engine version |
| `.status` | Show world status |
| `.quit` | Save and exit |

---

## World Commands

Spawn a player:

```text
SPAWN PLAYER <id> <username> <email>
````

List all players:

```text
LIST PLAYERS
```

---

# Running Chronicle

Start the server with a world file:

```bash
./chronicle <world_file>
```

Example:

```bash
./chronicle ironhold.world
```

The world file is created automatically if it does not exist.

---

# Project Structure

```
chronicle/
├── include/
│   ├── application_state.hpp
│   ├── command.hpp
│   ├── entity.hpp
│   ├── pager.hpp
│   ├── player.hpp
│   └── world_state.hpp
│
├── src/
│   ├── main.cpp
│   ├── command.cpp
│   ├── entity.cpp
│   ├── pager.cpp
│   └── world_state.cpp
│
├── tests/
│
├── Makefile
└── README.md
```

---

# Build

Compile the project:

```bash
make
```

Run the application:

```bash
 ./chronicle ironhold.world
```

Clean generated files:

```bash
make clean
```

---

# Current Status

*  Milestone 1 — Debug Console
*  Milestone 2 — Entity Commands and World State
*  Milestone 3 — Persistent World Storage

```
```
