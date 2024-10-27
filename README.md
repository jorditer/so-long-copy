# So Long

**So Long** is a simple 2D game where the player must collect all collectibles and find an exit to complete the level. The game is developed in C using MLX42, and adaptation of the MiniLibX graphical library, with a focus on handling textures, sprites, and basic gameplay mechanics.

<br>

![Descripción de la imagen](https://private-user-images.githubusercontent.com/147188123/380523638-0e2db797-a975-434d-a37a-2cbdf99a9aae.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzAwNTY1NzgsIm5iZiI6MTczMDA1NjI3OCwicGF0aCI6Ii8xNDcxODgxMjMvMzgwNTIzNjM4LTBlMmRiNzk3LWE5NzUtNDM0ZC1hMzdhLTJjYmRmOTlhOWFhZS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQxMDI3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MTAyN1QxOTExMThaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT05MGU0YTE1MTA3ZTg0NmI5ZGY1MmI0N2JkOTIzMTdlYzIwZWNlNmIxNjkyYTkzOTk0OWY3NTZlZmU5MmU4YmFmJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.r-RUz5xQ_51EDbQg7hww96mZI3LJmOJqAtLDz3zyAjY)

<br>

## How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/dracudev/So-Long
   ```
2. Navigate into the cloned directory and run make. This will compile all the source files and create the game.

   ```bash
   cd So-Long
   make
   ```
   
3. Run the game with a .ber map file:
   ```bash
   ./so_long /map/map1.ber
   ```   
4. You can use the provided maps or create your own custom maps following the [map guidelines](#map-requirements).

5. Additional Makefile Commands:

  - `make clean`: Removes all the object files (*.o) created during the compilation process. This is useful for cleaning up the directory without removing the compiled libraries and the game.
    
  - `make fclean`: Performs a deeper clean by removing all the object files as well as the compiled libraries and the game. This essentially resets the directory to its initial state before compilation.

  - `make re`: Combines the fclean and make commands to first remove all compiled files and then recompile the entire game. This is useful if you want to ensure a completely fresh build.

<br>

## Project Summary

This project is designed to enhance your skills in C programming and graphical management using MiniLibX. You will work with event handling, window management, and the display of 2D textures to create a small game. The game involves navigating a character through a maze, collecting items, and reaching an exit.

<br>

## Features

- **2D Game**: The game is rendered from a top-down perspective.
- **Movement**: The player can move in four directions (W, A, S, D).
- **Collectibles**: The player must collect all items on the map before reaching the exit.
- **Map Validation**: The map follows specific rules for structure and components, such as walls, spaces, collectibles, and an exit.
- **Movement Counter**: Every move is counted and displayed in the terminal.
- **Error Handling**: The program handles errors like invalid map structure or duplicate characters.

<br>

## Gameplay

The goal of the game is to collect every collectible on the map and reach the exit with the least amount of moves possible. The player cannot move through walls and must follow the correct path to complete the level.

### Controls:
- `W`, `A`, `S`, `D`: Move the character.
- `ESC`: Exit the game.

<br>

## Map Requirements

The map file passed as an argument to the game must adhere to the following rules:
- **Components**: 
  - `1`: Wall
  - `0`: Empty space
  - `C`: Collectible
  - `E`: Exit
  - `P`: Player start position
- **Structure**: 
  - The map must be rectangular.
  - It must be surrounded by walls (`1`).
  - It should have one exit (`E`), one player start position (`P`) and at least one collectible (`C`).

<br>

## Bonus Features
> Not implemented yet

   - Enemy patrols that make the player lose when touched.
   - Sprite animations.
   - Displaying the movement count directly in the game window rather than in the terminal.

<br>

## Credits

- This project uses the [MLX42](https://github.com/codam-coding-college/MLX42), an adaptation of [MiniLibX](https://github.com/42Paris/minilibx-linux) library for window and image management.
- The sprites are sourced from Itch.io:
   - [Dungeon Tileset II](https://0x72.itch.io/dungeontileset-ii)
   - [RPG Icon Pack: Jewels and Gems](https://clockworkraven.itch.io/rpg-icon-pack-jewels-and-gems)


<br>

## Implementation
