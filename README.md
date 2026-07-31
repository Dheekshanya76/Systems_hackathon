# Systems_hackathon
# Chronicle - Ironhold World Engine

Chronicle is the backend world-state engine for **Ironhold**, an open-world survival game. This project is being developed milestone by milestone as part of the Systems Hackathon.

## Milestone 1 - Game Debug Console

### Features

- Interactive console with `ironhold>` prompt
- Meta commands:
  - `.help`
  - `.version`
  - `.status`
  - `.quit`
- Unknown meta-command handling
- World command stub for non-dot commands
- Empty line handling

## Project Structure

```
chronicle/
├── include/
│   └── application_state.hpp
├── src/
│   └── main.cpp
├── tests/
├── Makefile
└── README.md
```

## Build

```bash
make
```

## Run

```bash
./chronicle
```

## Example

```
ironhold> .help
.quit       Shut down the world engine
.help       Show this message
.version    Show engine version
.status     Show world status

ironhold> .version
Chronicle v0.1 - Ironhold World Engine

ironhold> spawn player 1 alice
[World command queued: spawn player 1 alice]

ironhold> .status
World: offline

ironhold> .quit
```
