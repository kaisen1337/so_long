# So_Long

## 📋 About

`so_long` is a small 2D game where a player navigates through a map, collecting items and finding the exit while avoiding enemies. This project is part of the 42 School curriculum and uses the MiniLibX graphics library to create a simple yet engaging gaming experience.

## 🎯 Objective

The goal is simple:
- Collect all collectibles on the map
- Reach the exit
- Avoid enemies (in bonus version)
- Complete the level in as few moves as possible

## 🚀 Installation & Compilation

```bash
# Clone the repository
git clone https://github.com/kaisen1337/so_long.git
cd so_long

# Compile the mandatory part
make

# Compile with bonus features
make bonus
```

## 🎮 How to Play

```bash
# Run the game with a map file
./so_long maps/map1.ber

# Or run the bonus version
./so_long_bonus maps/bonus1.ber
```

### Controls

- **↑**: Move up
- **←**: Move left
- **↓**: Move down
- **→**: Move right
- **ESC**: Quit game

## 🗺️ Map Format

Maps must have the `.ber` extension and follow these rules:

### Map Components
- `0`: Empty space
- `1`: Wall
- `C`: Collectible
- `E`: Exit
- `P`: Player starting position
- `X`: Enemy (bonus version only)

### Map Requirements
- Must be rectangular
- Must be enclosed by walls
- Must contain 1 exit, at least 1 collectible, and exactly 1 player

### Example Map
```
1111111111111
1001000000001
1000011111001
1P0011E000001
1000C10C00C01
1111111111111
```

## ✨ Features

### Mandatory
- Clean map parsing and validation
- Smooth graphics rendering with MiniLibX
- Proper error handling and memory management
- Player movement with collision detection
- Path validation (ensuring all collectibles and the exit are reachable)
- Game state handling (win conditions, move counting)

### Bonus
- Animated sprites for player, collectibles, and exit
- Enemy patrols that end the game on contact
- On-screen move counter
- Smooth visual transitions
- Enhanced game UI elements

## 🔧 Technical Details

- Written in C
- Uses the MiniLibX graphics library
- Implements proper memory management
- Handles window events (keypress, window closing)
- Includes map validation algorithms
- Uses a game loop architecture

## 📝 Project Structure

```
so_long/
├── includes/           # Header files
├── src/                # Source files
│   ├── mandatory/      # Main game logic
│   └── bonus/          # Bonus features
├── maps/               # Map files
├── assets/             # Game sprites and textures
├── Makefile            # Compilation instructions
└── README.md           # Project documentation
```

## 🚀 Skills Developed

- Graphics programming
- Game development concepts
- Event handling
- Memory management
- File parsing
- Algorithm implementation (path finding)
- Error handling

## 📜 License

This project is part of the 42 School curriculum and is for educational purposes.

---

*Created by **kaisen1337** - Last updated: February 26, 2025*
