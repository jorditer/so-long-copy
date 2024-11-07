# So Long

**So Long** is a simple 2D game where the player must collect all collectibles and find an exit to complete the level. The game is developed in C using MLX42, and adaptation of the MiniLibX graphical library, with a focus on handling textures, sprites, and basic gameplay mechanics.

<br>

![so_long](assets/so_long.png)

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

This project is designed to enhance your skills in C programming and graphical management using MLX42. You will work with event handling, window management, and the display of 2D textures to create a small game. The game involves navigating a character through a maze, collecting items, and reaching an exit.

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
  - There must be a valid path from the player (`P`) to all collectibles (`C`) and the exit (`E`).

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

# Implementation

## Error Handling
### [ft_error](src/errors.c)

The `ft_error` function displays an error message prefixed with `[ERROR]` and terminates the program with a non-zero exit status.

```c
void	ft_error(char *msg)
{
	ft_printf("[ERROR] %s\n", msg);
	exit(1);
}
````

**Parameters**:
- `char *msg`: A pointer to the string containing the error message to be displayed.

**Functionality**:
- Prints an error message to standard output, prefixed with `[ERROR]`, followed by the specified message.
- Immediately terminates the program using `exit(1)`, indicating an error occurred.

<br>

### [ft_error_clean](src/errors.c)

The `ft_error_clean` function displays an error message prefixed with `[ERROR]`, performs cleanup of allocated resources, and terminates the program with a non-zero exit status.

```c
void	ft_error_clean(char *msg, t_game *game)
{
	ft_printf("[ERROR] %s\n", msg);
	clean_up(game);
	exit(1);
}
```

**Parameters**:
- `char *msg`: A pointer to the string containing the error message to be displayed.
- `t_game *game`: A pointer to the `t_game` structure, used to manage and free allocated resources before exiting.

**Functionality**:
- Prints an error message to standard output, prefixed with `[ERROR]`, followed by the specified message.
- Calls the `clean_up` function to free any resources associated with the `game` structure.
- Terminates the program using `exit(1)`, indicating an error occurred.

<br>

## Utility
### [clean_up](src/delete.c)

The `clean_up` function releases resources and memory allocated within the `game` structure, ensuring no memory leaks when the game exits.

```c
void	clean_up(t_game *game)
{
	delete_images(game);
	delete_textures(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map.array || game->map.info)
		free_map(game);
	if (game->fd > 0)
		close(game->fd);
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure that holds resources (images, textures, map data, etc.) to be freed.

**Functionality**:
- Calls `delete_images` and `delete_textures` functions to free any images and textures allocated within the `game`.
- Terminates the `mlx` session if it exists by calling `mlx_terminate`.
- Frees map data within `game` by calling `free_map` if either `map.array` or `map.info` is allocated.
- Closes the file descriptor `fd` if it is open (greater than 0).

<br>

### [line_len](src/utils.c)

The `line_len` function calculates the length of a given string until the newline character (`\n`) is encountered, replacing it with a null terminator (`\0`) if found.

```c
int	line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (i);
}
```

**Parameters**:
- `char *str`: A pointer to the string whose length will be calculated up to the newline character.

**Functionality**:
- Initializes an index counter `i` to zero.
- Iterates through each character in the string `str`:
  - If a newline character (`\n`) is found, it is replaced by a null terminator (`\0`), effectively marking the end of the string.
- Returns the length of the string as an integer, which is the total count of characters until the newline or the end of the string.

<br>

### [check_args](src/utils.c)

The `check_args` function verifies that the correct number of arguments is provided and that the map file has the `.ber` extension.

```c
void	check_args(int argc, char **argv)
{
	int	map_len;

	if (argc != 2)
		ft_error("Invalid number of arguments.");
	map_len = ft_strlen(argv[1]);
	if (ft_strnstr(&argv[1][map_len - 4], ".ber", 4) == NULL)
		ft_error("Invalid map extension.");
}
```

**Parameters**:
- `int argc`: The number of command-line arguments passed to the program.
- `char **argv`: An array of strings containing the command-line arguments.

**Functionality**:
- Checks if `argc` equals 2 (expects exactly one argument for the map file). If not, it calls `ft_error` with a message indicating an invalid number of arguments.
- Computes the length of the map file name in `argv[1]` and verifies if it ends with the `.ber` extension by calling `ft_strnstr`. If the extension is incorrect, it calls `ft_error` with a message indicating an invalid map extension.

<br>

### [init_value](src/utils.c)

The `init_value` function initializes the fields of the `game` structure, setting default values for the game's starting state and ensuring pointers are `NULL` before allocation.

```c
void	init_value(t_game *game)
{
	game->position.x = 0;
	game->position.y = 0;
	game->position.move = 0;
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.collect = 0;
	game->map.exit = 0;
	game->map.player = 0;
	game->map.walls = 0;
	game->map.floor = 0;
	game->map.info = NULL;
	game->map.exit_found = 0;
	game->count = 0;
	game->finish_game = 0;
	game->map.array = NULL;
	game->txt = NULL;
	game->img = NULL;
	game->mlx = NULL;
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure that holds various game-related values and settings.

**Functionality**:
- Sets initial values for `game` attributes, including:
  - `position` attributes (`x`, `y`, `move`) to zero, defining the player’s starting position and move count.
  - `map` attributes (`rows`, `columns`, `collect`, `exit`, `player`, `walls`, `floor`, `exit_found`) to zero, initializing map properties such as row/column counts, collectible items, exits, and wall/floor statuses.
  - `map.info` and `map.array` to `NULL`, indicating no map data has been loaded yet.
  - `count` and `finish_game` to zero, marking game counters and completion status.
  - `txt`, `img`, and `mlx` pointers to `NULL`, preparing for texture, image, and MLX initialization.

<br>

## Map Parsing
### [map_calloc](src/map_parser.c)

The `map_calloc` function allocates memory for the `map.array` in the `game` structure, ensuring it can store up to 270 rows of map data.

```c
static void	map_calloc(t_game *game)
{
	if (!game->map.array)
	{
		game->map.array = ft_calloc(270, sizeof(char *));
		if (!game->map.array)
			ft_error_clean("Memmory allocation for map failed.", game);
	}
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure that contains the map data to be allocated.

**Functionality**:
- Checks if `map.array` is `NULL`. If so, it allocates memory for 270 pointers to `char` using `ft_calloc`.
- If the allocation fails, it calls `ft_error_clean` with a message indicating memory allocation failure and performs cleanup.

<br>

### [map_len](src/map_parser.c)

The `map_len` function updates the column count of the map in the `game` structure based on the length of a given line and checks if the line exceeds the maximum allowed width.

```c
static void	map_len(t_game *game, char *line, int i)
{
	int	len;

	len = line_len(line);
	if (i == 0)
		game->map.columns = len;
	if (len >= MAP_WIDTH / IMG_W)
		ft_error_clean("Map file too long.", game);
	return ;
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure where the map properties are stored.
- `char *line`: A pointer to the current line of the map being processed.
- `int i`: The index of the current line, used to determine if it's the first line.

**Functionality**:
- Calculates the length of the provided line using the `line_len` function.
- If `i` is `0`, it sets `game->map.columns` to the length of the first line, establishing the column count for the map.
- If the length of the line is greater than or equal to `MAP_WIDTH / IMG_W`, it calls `ft_error_clean` with a message indicating the map file is too long and performs cleanup.

<br>

### [map_parser](src/map_parser.c)

The `map_parser` function reads lines from a map file, allocates memory for each line, and populates the `map.array` in the `game` structure while ensuring the map adheres to defined dimensions.

```c
void	map_parser(t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(game->fd);
	if (line == NULL)
		ft_error_clean("Map file is empty.", game);
	i = 0;
	while (line && (line[0] != '\n'))
	{
		if (i >= MAP_HEIGHT / IMG_H)
			ft_error_clean("Map file too high.", game);
		if (game->map.array == NULL)
			map_calloc(game);
		game->map.array[i] = malloc(sizeof(char) * (line_len(line) + 1));
		if (!game->map.array[i])
			ft_error_clean("Error allocating map rows", game);
		map_len(game, line, i);
		ft_strlcpy(game->map.array[i], line, game->map.columns + 1);
		i++;
		free(line);
		line = get_next_line(game->fd);
	}
	game->map.rows = i;
	free(line);
	close(game->fd);
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure where the map data will be stored.

**Functionality**:
- Reads the first line from the map file using `get_next_line`. If the line is `NULL`, it calls `ft_error_clean` with a message indicating the map file is empty.
- Initializes a line counter `i` to zero.
- Enters a loop to read lines from the map file until a newline character is encountered:
  - If the number of lines read (`i`) exceeds the maximum allowed height (`MAP_HEIGHT / IMG_H`), it calls `ft_error_clean` with a message indicating the map file is too high.
  - Calls `map_calloc` to allocate memory for `map.array` if it is still `NULL`.
  - Allocates memory for the current row in `map.array` based on the length of the line plus one for the null terminator. If allocation fails, it calls `ft_error_clean` with a relevant message.
  - Calls `map_len` to update the column count of the map.
  - Copies the contents of the line into the current row of `map.array` using `ft_strlcpy`.
  - Increments the line counter `i`, frees the current line, and reads the next line from the file.
- After processing all lines, sets `game->map.rows` to the total count of lines read, frees the last line, and closes the file descriptor.

<br>

### [copy_map](src/pathfinding.c)

The `copy_map` function allocates memory for a copy of the map information and fills it with the data from the original map array.

```c
static void	copy_map(t_game *game)
{
	int	i;

	if (!game->map.info)
	{
		game->map.info = (char **)malloc(sizeof(char *) * (game->map.rows + 1));
		if (!game->map.info)
			ft_error_clean("Allocation failed for map rows info.", game);
		i = 0;
		while (i < game->map.rows)
		{
			game->map.info[i] = malloc(sizeof(char) * (game->map.columns + 1));
			if (!game->map.info[i])
				ft_error_clean("Allocation failed for map columns info.", game);
			ft_strlcpy(game->map.info[i], game->map.array[i], \
					game->map.columns + 1);
			i++;
		}
		game->map.info[i] = NULL;
	}
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure that contains the original map data.

**Functionality**:
- Checks if `game->map.info` is `NULL`. If it is, it allocates memory for an array of strings (`char **`) to hold the map rows, with a size of `game->map.rows + 1` for the null terminator. If allocation fails, it calls `ft_error_clean` with a message indicating the failure to allocate memory for map rows.
- Initializes a row index `i` to `0` and enters a loop that iterates over each row of the original map:
  - Allocates memory for each row in `game->map.info` based on the number of columns (`game->map.columns + 1` for the null terminator). If allocation fails, it calls `ft_error_clean` with a relevant message.
  - Copies the contents of each row from `game->map.array` into the corresponding row of `game->map.info` using `ft_strlcpy`.
- After copying all rows, sets the last entry of `game->map.info` to `NULL`, indicating the end of the array.

<br>


## Map Checking
### [is_rectangular](src/map_checker.c)

The `is_rectangular` function checks whether the map in the `game` structure is rectangular by verifying that each row has the same length as the first row.

```c
static int	is_rectangular(t_game *game)
{
	size_t	len;
	int		i;

	if (!game->map.array || !game->map.array[0])
		ft_error("Map is empty or invalid.");
	len = ft_strlen(game->map.array[0]);
	i = 1;
	while (game->map.array[i])
	{
		if (ft_strlen(game->map.array[i]) != len)
			ft_error("Map is not rectangular.");
		i++;
	}
	return (0);
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure containing the map data to be validated.

**Functionality**:
- Checks if `map.array` or its first element is `NULL`. If either is `NULL`, the function calls `ft_error` with a message indicating the map is empty or invalid.
- Stores the length of the first row in `len`.
- Iterates over each subsequent row in `map.array`:
  - If any row length does not match `len`, it calls `ft_error` with a message indicating the map is not rectangular.
- Returns `0` if all rows are of equal length, confirming the map is rectangular.

<br>

### [is_surrounded_by_walls](src/map_checker.c)

The `is_surrounded_by_walls` function checks if the map is correctly enclosed by walls (`'1'`) on all sides, ensuring that the first and last rows, as well as the first and last columns of each row, are bounded by wall characters.

```c
static int	is_surrounded_by_walls(t_game *game)
{
	int	i;
	int	last_row;

	if (!game->map.array || !game->map.array[0])
		ft_error("Map is empty or invalid.");
	last_row = 0;
	while (game->map.array[last_row])
		last_row++;
	last_row--;
	i = 0;
	while (game->map.array[0][i] && game->map.array[last_row][i])
	{
		if (game->map.array[0][i] != '1' || game->map.array[last_row][i] != '1')
			ft_error("Top or bottom row not enclosed by walls.");
		i++;
	}
	i = 0;
	while (game->map.array[i])
	{
		if (game->map.array[i][0] != '1'
				|| game->map.array[i][ft_strlen(game->map.array[i]) - 1] != '1')
			ft_error("Left or right not enclosed by walls.");
		i++;
	}
	return (0);
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure containing the map data to be validated.

**Functionality**:
- Checks if `map.array` or its first element is `NULL`. If either is `NULL`, it calls `ft_error` with a message indicating the map is empty or invalid.
- Determines the index of the last row in the map.
- Iterates over each character in the first and last rows:
  - If any character in the top or bottom row is not `'1'`, it calls `ft_error` with a message indicating that the top or bottom row is not enclosed by walls.
- Iterates over each row to check the leftmost and rightmost characters:
  - If any character in the first or last column of any row is not `'1'`, it calls `ft_error` with a message indicating that the left or right side is not enclosed by walls.
- Returns `0` if all checks pass, confirming the map is properly enclosed by walls.

<br>

### [invalid_components](src/map_checker.c)

The `invalid_components` function checks the components of the map at a specific position to ensure they are valid, and it tracks the player's position if found.

```c
static void	invalid_components(t_game *game, int i, int j)
{
	if (game->map.array[i][j] != 'E' && game->map.array[i][j] != 'P'
			&& game->map.array[i][j] != 'C' && game->map.array[i][j] != 'E'
			&& game->map.array[i][j] != '1' && game->map.array[i][j] != '0')
		ft_error("Invalid components.");
	if (game->map.array[i][j] == 'P')
	{
		game->map.player++;
		game->position.x = j;
		game->position.y = i;
	}
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure containing the map data.
- `int i`: The row index of the current map component being checked.
- `int j`: The column index of the current map component being checked.

**Functionality**:
- Checks if the character at the specified position in the map is not one of the valid components (`'E'`, `'P'`, `'C'`, `'1'`, `'0'`). If the character is invalid, it calls `ft_error` with a message indicating the presence of invalid components.
- If the character is `'P'` (indicating the player's starting position):
  - Increments the `player` count in the `game->map` structure.
  - Updates the player's position coordinates (`game->position.x` and `game->position.y`) to the current indices `j` and `i`.

<br>

### [validate_map_components](src/map_checker.c)

The `validate_map_components` function checks the components of the map for validity, ensuring the correct number of exits, players, and collectibles are present.

```c
static int	validate_map_components(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j])
		{
			if (game->map.array[i][j] == 'E')
				game->map.exit++;
			if (game->map.array[i][j] == 'C')
				game->map.collect++;
			invalid_components(game, i, j);
			j++;
		}
		i++;
	}
	if (game->map.exit != 1 || game->map.player != 1 || game->map.collect < 1)
		ft_error("Invalid number of components.");
	return (0);
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure containing the map data to be validated.

**Functionality**:
- Initializes row index `i` to `0` and iterates through each row of the map until reaching the end:
  - Initializes column index `j` to `0` and iterates through each character in the current row:
    - Increments the `exit` count if the character is `'E'` (exit).
    - Increments the `collect` count if the character is `'C'` (collectible).
    - Calls the `invalid_components` function to check if the current character is valid and track the player's position if necessary.
- After processing all components, checks if the number of exits, players, and collectibles meets the required criteria:
  - There must be exactly one exit (`exit`), exactly one player (`player`), and at least one collectible (`collect`). If not, it calls `ft_error` with a message indicating an invalid number of components.
- Returns `0` if all validations pass successfully.

<br>

### [flood_fill](src/pathfinding.c)

The `flood_fill` function recursively marks reachable areas of the map starting from a given position, checking for collectibles and the exit.

```c
void	flood_fill(t_game *game, int x, int y, int *collect)
{
	if (x < 0 || y < 0 || x >= game->map.columns || y >= game->map.rows
		|| game->map.info[y][x] == '1' || game->map.info[y][x] == 'V')
		return ;
	if (game->map.info[y][x] == 'C')
		(*collect)--;
	if (game->map.info[y][x] == 'E')
		game->map.exit_found = 1;
	game->map.info[y][x] = 'V';
	flood_fill(game, x + 1, y, collect);
	flood_fill(game, x - 1, y, collect);
	flood_fill(game, x, y + 1, collect);
	flood_fill(game, x, y - 1, collect);
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure containing the map data.
- `int x`: The x-coordinate of the current position being checked.
- `int y`: The y-coordinate of the current position being checked.
- `int *collect`: A pointer to an integer tracking the number of collectibles that need to be collected.

**Functionality**:
- Checks if the current position (`x`, `y`) is out of bounds or if the cell is a wall (`'1'`) or already visited (`'V'`). If so, it returns without making any changes.
- If the current cell is a collectible (`'C'`), it decrements the `collect` counter.
- If the current cell is an exit (`'E'`), it sets the `exit_found` flag in the `game->map` structure to `1`, indicating that the exit is reachable.
- Marks the current cell as visited by changing its value to `'V'`.
- Recursively calls `flood_fill` on the neighboring cells (right, left, down, up).

<br>

### [pathfinding](src/pathfinding.c)

The `pathfinding` function initiates the process to find a valid path in the map, ensuring all collectibles and the exit are reachable.

```c
int	pathfinding(t_game *game)
{
	int	collect;

	collect = game->map.collect;
	copy_map(game);
	flood_fill(game, game->position.x, game->position.y, &collect);
	if (collect > 0 || !game->map.exit_found)
		ft_error("Not all collectibles or exit are reachable.");
	return (0);
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure containing the map data.

**Functionality**:
- Initializes a local variable `collect` to track the number of collectibles from the `game->map` structure.
- Calls the `copy_map` function to create a copy of the map information.
- Calls `flood_fill` starting from the player's current position (`game->position.x`, `game->position.y`) to explore reachable areas and update the `collect` counter.
- After the flood fill, checks if there are still collectibles left or if the exit was not found. If either condition is true, it calls `ft_error` with a message indicating that not all collectibles or the exit are reachable.
- Returns `0` if all checks pass successfully.

<br>

### [map_checker](src/map_checker.c)

The `map_checker` function validates the map structure and its components, ensuring that it adheres to the required specifications.

```c
int	map_checker(t_game *game)
{
	if (is_rectangular(game) == 1)
		return (1);
	if (is_surrounded_by_walls(game) == 1)
		return (1);
	if (validate_map_components(game) == 1)
		return (1);
	if (pathfinding(game) == 1)
		return (1);
	return (0);
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure containing the map data.

**Functionality**:
- Calls the `is_rectangular` function to check if the map is rectangular. If the map is not rectangular, it returns `1` to indicate an error.
- Calls the `is_surrounded_by_walls` function to verify that the map is enclosed by walls. If the check fails, it returns `1` to indicate an error.
- Calls the `validate_map_components` function to ensure all required components (player, exit, collectibles) are present and valid. If the validation fails, it returns `1`.
- Calls the `pathfinding` function to determine if all collectibles and the exit are reachable from the player's starting position. If the pathfinding fails, it returns `1`.
- If all checks pass, the function returns `0`, indicating that the map is valid.

<br>


## Map Cleanup
### [free_map_array](src/errors.c)

The `free_map_array` function deallocates memory for a 2D array representing the map.

```c
static void	free_map_array(char **map, int columns)
{
	int	i;

	if (!map || !*map)
		ft_error("Map data not found or invalid.");
	i = 0;
	while (i < columns && map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
```

**Parameters**:
- `char **map`: A pointer to the array of strings that represents the map.
- `int columns`: The number of columns (or rows) in the map array.

**Functionality**:
- Checks if the `map` is `NULL` or points to an empty string. If so, it calls `ft_error` to signal that the map data is invalid.
- Iterates through each row of the `map` up to the specified number of columns, freeing each allocated string.
- Finally, frees the array itself, ensuring no memory leaks occur.

<br>

### [free_map_info](src/errors.c)

The `free_map_info` function deallocates memory for a 2D array containing map information.

```c
static void	free_map_info(char **vector)
{
	int	i;

	if (!vector || !*vector)
		ft_error("Invalid map data.");
	i = 0;
	while (vector[i] != NULL)
	{
		free(vector[i]);
		i++;
	}
	free(vector);
}
```

**Parameters**:
- `char **vector`: A pointer to the array of strings that holds the map information.

**Functionality**:
- Checks if the `vector` is `NULL` or points to an empty string. If so, it calls `ft_error` to indicate that the map data is invalid.
- Iterates through each string in the `vector` until a `NULL` pointer is encountered, freeing each allocated string.
- Finally, frees the array itself, ensuring proper memory management and preventing leaks.

<br>

### [free_map](src/errors.c)

The `free_map` function is responsible for freeing the allocated memory used for the map data in the `t_game` structure.

```c
void	free_map(t_game *game)
{
	free_map_array(game->map.array, game->map.columns);
	if (game->map.info != NULL)
		free_map_info(game->map.info);
}
```

**Parameters**:
- `t_game *game`: A pointer to the `t_game` structure containing the map data.

**Functionality**:
- Calls the `free_map_array` function to free the memory allocated for the map array (`game->map.array`). This function iterates through each row of the map and frees the allocated memory for each string before freeing the array itself.
- Checks if the map information (`game->map.info`) is not `NULL`. If it exists, it calls the `free_map_info` function to free the memory allocated for the map information. This function iterates through the map information and frees each string before freeing the array.

<br>

## Graphics
### [init_textures](src/graphics.c)

The `init_textures` function initializes the textures for the game by allocating memory and loading the necessary image files.

```c
static int	init_textures(t_game *game)
{
	game->txt = ft_calloc(1, sizeof(t_txt));
	if (!game->txt)
		ft_error_clean("Failled allocation for textures", game);
	game->txt->floor = mlx_load_png("./assets/floor1.png");
	game->txt->wall = mlx_load_png("./assets/wall.png");
	game->txt->exit1 = mlx_load_png("./assets/exit1.png");
	game->txt->exit2 = mlx_load_png("./assets/exit2.png");
	game->txt->pnj = mlx_load_png("./assets/pnj.png");
	game->txt->collect = mlx_load_png("./assets/collect.png");
	if (!game->txt->floor || !game->txt->wall || !game->txt->exit1
		|| !game->txt->exit2 || !game->txt->pnj || !game->txt->collect)
		ft_error_clean("Failed loading textures", game);
	return (0);
}
```

**Parameters**:
- `t_game *game`: A pointer to the game structure that holds all game-related data, including textures.

**Functionality**:
- Allocates memory for the `txt` field in the `game` structure using `ft_calloc`. If the allocation fails, it calls `ft_error_clean` to handle the error and clean up.
- Loads various textures from PNG files located in the `./assets/` directory into the `txt` structure:
  - `floor`: The texture for the floor.
  - `wall`: The texture for the wall.
  - `exit1` and `exit2`: Textures for exit points.
  - `pnj`: The texture for a non-player character.
  - `collect`: The texture for collectible items.
- If any texture fails to load, it calls `ft_error_clean` to handle the error appropriately.
- Returns `0` on successful initialization.

<br>

### [init_images](src/graphics.c)

The `init_images` function initializes the images for the game by allocating memory for the image structure and converting loaded textures into images.

```c
static int	init_images(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_img));
	if (!game->img)
		ft_error_clean("Failed allocation for images", game);
	game->img->floor = mlx_texture_to_image(game->mlx, game->txt->floor);
	game->img->wall = mlx_texture_to_image(game->mlx, game->txt->wall);
	game->img->exit1 = mlx_texture_to_image(game->mlx, game->txt->exit1);
	game->img->exit2 = mlx_texture_to_image(game->mlx, game->txt->exit2);
	game->img->pnj = mlx_texture_to_image(game->mlx, game->txt->pnj);
	game->img->collect = mlx_texture_to_image(game->mlx, game->txt->collect);
	if (!game->img->floor || !game->img->wall || !game->img->exit1
		|| !game->img->exit2 || !game->img->pnj || !game->img->collect)
		ft_error_clean("Failed creating images from textures", game);
	delete_textures(game);
	return (0);
}
```

**Parameters**:
- `t_game *game`: A pointer to the game structure that contains all game-related data, including textures and images.

**Functionality**:
- Allocates memory for the `img` field in the `game` structure using `ft_calloc`. If the allocation fails, it calls `ft_error_clean` to handle the error and clean up.
- Converts the previously loaded textures to images using `mlx_texture_to_image` for the following elements:
  - `floor`: The image for the floor.
  - `wall`: The image for the wall.
  - `exit1` and `exit2`: Images for the exit points.
  - `pnj`: The image for a non-player character.
  - `collect`: The image for collectible items.
- If any image conversion fails, it calls `ft_error_clean` to handle the error appropriately.
- Calls `delete_textures(game)` to free the previously allocated textures to avoid memory leaks.
- Returns `0` on successful initialization.

<br>

### [draw_map](src/graphics.c)

The `draw_map` function is responsible for rendering the game map in the game window by drawing different images based on the map array.

```c
static void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.array[y])
	{
		x = 0;
		while (game->map.array[y][x])
		{
			mlx_image_to_window(game->mlx, game->img->floor, \
					x * IMG_W, y * IMG_H);
			if (game->map.array[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img->wall, \
						x * IMG_W, y * IMG_H);
			if (game->map.array[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, game->img->exit2, \
						x * IMG_W, y * IMG_H);
				mlx_image_to_window(game->mlx, game->img->exit1, \
						x * IMG_W, y * IMG_H);
			}
			x++;
		}
		y++;
	}
}
```

**Parameters**:
- `t_game *game`: A pointer to the game structure that contains all game-related data, including the map layout and images.

**Functionality**:
- Initializes two variables, `x` and `y`, to iterate over the `map.array`, which holds the representation of the game map.
- For each row `y` in the map:
  - Iterates through each column `x`.
  - Calls `mlx_image_to_window` to draw the floor image at the calculated position `(x * IMG_W, y * IMG_H)` for each tile.
  - Checks the value of `game->map.array[y][x]` to determine what image to draw:
    - If the tile is a wall (`'1'`), it draws the wall image at the same position.
    - If the tile is an exit (`'E'`), it draws two exit images at the same position, allowing for a layered effect.
- Continues until the entire map is drawn on the window.

**Note**: The drawing order is important to ensure that the floor is rendered first before walls or exits.

<br>

### [draw_items](src/drawing.c)

The `draw_items` function is responsible for rendering special game items such as collectibles and the player character on the game map.

```c
static void	draw_items(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.array[y])
	{
		x = 0;
		while (game->map.array[y][x])
		{
			if (game->map.array[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img->collect, \
						x * IMG_W, y * IMG_H);
			if (game->map.array[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->img->pnj, \
						x * IMG_W, y * IMG_H);
			x++;
		}
		y++;
	}
}
```

**Parameters**:
- `t_game *game`: A pointer to the game structure that holds information about the current state of the game, including the map and images.

**Functionality**:
- Initializes two variables, `x` and `y`, to iterate over the `map.array`, which represents the game map layout.
- For each row `y` in the map:
  - Iterates through each column `x`.
  - Checks the value of `game->map.array[y][x]` to determine what item to draw:
    - If the tile contains a collectible (`'C'`), it draws the collectible image at the calculated position `(x * IMG_W, y * IMG_H)`.
    - If the tile contains the player character (`'P'`), it draws the player image at the same position.
- Continues until all items on the map are drawn.

**Note**: This function should be called after the `draw_map` function to ensure that items are rendered on top of the floor and walls, maintaining the correct visual hierarchy in the game window.

<br>

### [init_graphics](src/graphics.c)

The `init_graphics` function initializes all the previous functions.

```c
void	init_graphics(t_game *game)
{
	init_textures(game);
	init_images(game);
	draw_map(game);
	draw_items(game);
}
```

<br>

### [delete_textures](src/delete.c)

The `delete_textures` function is responsible for deallocating memory and cleaning up the texture resources used in the game. This helps prevent memory leaks by ensuring that all allocated textures are properly freed when they are no longer needed.

```c
void	delete_textures(t_game *game)
{
	if (game->txt)
	{
		if (game->txt->floor)
			mlx_delete_texture(game->txt->floor);
		if (game->txt->wall)
			mlx_delete_texture(game->txt->wall);
		if (game->txt->exit1)
			mlx_delete_texture(game->txt->exit1);
		if (game->txt->exit2)
			mlx_delete_texture(game->txt->exit2);
		if (game->txt->pnj)
			mlx_delete_texture(game->txt->pnj);
		if (game->txt->collect)
			mlx_delete_texture(game->txt->collect);
		free(game->txt);
		game->txt = NULL;
	}
}
```

**Parameters**:
- `t_game *game`: A pointer to the game structure that contains the texture information to be deleted.

**Functionality**:
   - First, the function checks if the `game->txt` pointer is not NULL, indicating that textures have been allocated.
   - For each texture (floor, wall, exits, player, and collectible), the function checks if the texture pointer is not NULL before calling `mlx_delete_texture` to release the associated memory.
   - This ensures that no attempt is made to delete a texture that has not been allocated.
   - After all individual textures have been deleted, the function frees the `game->txt` pointer itself and sets it to NULL to prevent dangling pointers.

<br>

### [delete_images](src/delete.c)

The `delete_images` function is responsible for deallocating the image resources used in the game. Properly managing image memory is crucial to avoid memory leaks and ensure efficient resource usage during the game's lifecycle.

```c
void	delete_images(t_game *game)
{
	if (game->img)
	{
		if (game->img->floor)
			mlx_delete_image(game->mlx, game->img->floor);
		if (game->img->wall)
			mlx_delete_image(game->mlx, game->img->wall);
		if (game->img->exit1)
			mlx_delete_image(game->mlx, game->img->exit1);
		if (game->img->exit2)
			mlx_delete_image(game->mlx, game->img->exit2);
		if (game->img->pnj)
			mlx_delete_image(game->mlx, game->img->pnj);
		if (game->img->collect)
			mlx_delete_image(game->mlx, game->img->collect);
		free(game->img);
		game->img = NULL;
	}
}
```

**Parameters**:
- `t_game *game`: A pointer to the game structure that contains the image information to be deleted.

**Functionality**:
- The function first checks if the `game->img` pointer is not NULL, which indicates that images have been allocated and are ready for deletion.
- For each image (floor, wall, exits, player, and collectible), the function checks if the corresponding image pointer is not NULL before calling `mlx_delete_image` to free the associated memory. This prevents attempts to delete images that haven't been allocated, ensuring stability.
- After all individual images have been deleted, the function frees the `game->img` pointer itself and sets it to NULL to prevent dangling references.

<br>


## Hooks
### [move_functions](src/hooks.c)

The movement functions (`move_up`, `move_down`, `move_right`, `move_left`) update the position of the player character in the game based on user input. Each function checks if the next tile in the respective direction is not a wall before moving the character.

```c
static void	move_up(t_game *game, int y, int x)
{
	if (game->map.array[(y - IMG_W) / IMG_W][x / IMG_H] != '1')
	{
		game->img->pnj->instances[0].y -= IMG_W;
		game->position.move++;
		ft_printf("MOVES: %i\n", game->position.move);
	}
}

static void	move_down(t_game *game, int y, int x)
{
	if (game->map.array[(y + IMG_W) / IMG_W][x / IMG_H] != '1')
	{
		game->img->pnj->instances[0].y += IMG_W;
		game->position.move++;
		ft_printf("MOVES: %i\n", game->position.move);
	}
}

static void	move_right(t_game *game, int y, int x)
{
	if (game->map.array[y / IMG_W][(x + IMG_H) / IMG_H] != '1')
	{
		game->img->pnj->instances[0].x += IMG_H;
		game->position.move++;
		ft_printf("MOVES: %i\n", game->position.move);
	}
}

static void	move_left(t_game *game, int y, int x)
{
	if (game->map.array[y / IMG_W][(x - IMG_H) / IMG_H] != '1')
	{
		game->img->pnj->instances[0].x -= IMG_H;
		game->position.move++;
		ft_printf("MOVES: %i\n", game->position.move);
	}
}
```

**Parameters**:
- `t_game *game`: A pointer to the game structure containing the current state of the game, including the map and player position.
- `int y`: The current vertical position of the player character.
- `int x`: The current horizontal position of the player character.

**Functionality**:
- Each function checks if the tile in the direction of movement is not a wall (i.e., not equal to '1').
- If the path is clear, the respective function updates the player character's position by adjusting the `y` or `x` coordinate accordingly.
- Increments the move counter (`game->position.move`) by 1 to track the number of moves made.
- Outputs the current number of moves to the console using `ft_printf`.

<br>

### [my_key_hook](src/hooks.c)

The `my_key_hook` function handles keyboard input to control the movement of the player character and manage game events. It checks for specific key presses and calls the appropriate movement functions or triggers game-related actions.

```c
void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		*y;
	int		*x;

	game = param;
	y = &game->img->pnj->instances[0].y;
	x = &game->img->pnj->instances[0].x;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
		move_up(game, *y, *x);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		move_right(game, *y, *x);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS))
		move_down(game, *y, *x);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
		move_left(game, *y, *x);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	pick_collect(game, *y, *x);
	finish_game(game, *y, *x);
}
```

**Parameters**:
- `mlx_key_data_t keydata`: A structure containing data about the key event, including which key was pressed and the action type (press or release).
- `void *param`: A pointer to the game structure, which contains the current state of the game.

**Functionality**:
- Retrieves the game state from the `param` pointer.
- Defines pointers to the player's current y and x coordinates for easy reference.
- Checks if specific movement keys are pressed (W, A, S, D or arrow keys) and calls the corresponding movement function (`move_up`, `move_down`, `move_left`, `move_right`) if a valid key is detected.
- If the Escape key is pressed, it closes the game window using `mlx_close_window`.
- Calls the `pick_collect` function to check if the player has collected any items at the current position.
- Calls the `finish_game` function to determine if the game has ended based on the player's current position.

<br>

## Logic
### [del_collect](src/logic.c)

The `del_collect` function removes a collectible item from the game when the player character interacts with it. It updates the collectible's state to disabled, effectively making it no longer visible or collectible.

```c
static void	del_collect(t_game *game, int y, int x)
{
	int	i;
	int	collects;

	i = 0;
	collects = game->map.collect;
	while (i < collects)
	{
		if (((game->img->collect->instances[i].y == y)
				&& (game->img->collect->instances[i].x == x))
			&& (game->img->collect->instances[i].enabled == true))
		{
			collects--;
			game->img->collect->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}
```


**Parameters**:
- `t_game *game`: A pointer to the game structure containing the current state of the game, including the map and collectibles.
- `int y`: The vertical position of the player character.
- `int x`: The horizontal position of the player character.

**Functionality**:
- Initializes a counter `i` to iterate through the list of collectibles and retrieves the total number of collectibles from `game->map.collect`.
- Iterates through each collectible instance to check for a match with the player's current position `(y, x)`.
- If a collectible is found at the specified position and is enabled, it:
  - Decrements the total number of collectibles.
  - Sets the `enabled` state of the collectible to `false`, indicating it has been collected.
  - Returns from the function to avoid further processing.

<br>

### [pick_collect](src/logic.c)

The `pick_collect` function checks if the player character has collected a collectible item at its current position. If so, it updates the game state accordingly.

```c
void	pick_collect(t_game *game, int y, int x)
{
	if (game->map.array[y / IMG_W][x / IMG_H] == 'C')
	{
		del_collect(game, y, x);
		game->map.array[y / IMG_W][x / IMG_H] = '0';
		game->count++;
		if (game->count == game->map.collect)
			game->img->exit1->instances->enabled = false;
	}
}
```

**Parameters**:
- `t_game *game`: A pointer to the game structure containing the current state of the game, including the map and collectibles.
- `int y`: The vertical position of the player character.
- `int x`: The horizontal position of the player character.

**Functionality**:
- Checks if the tile at the player's current position `(y / IMG_W, x / IMG_H)` is a collectible ('C').
- If a collectible is found:
  - Calls the `del_collect` function to mark the collectible as collected.
  - Updates the map array to change the collectible tile to '0', indicating it is no longer present.
  - Increments the collectible count (`game->count`) by 1.
  - If the count of collected items matches the total number of collectibles in the map, it disables the exit instance (`game->img->exit1->instances->enabled = false`), indicating that the player can exit the game.
 
<br>

### [finish_game](src/logic.c)

The `finish_game` function checks if the player character has reached the exit point of the game. If the player has collected all necessary items, it triggers the end of the game.

```c
void	finish_game(t_game *game, int y, int x)
{
	if (game->map.array[y / IMG_W][x / IMG_H] == 'E')
	{
		if (game->count == game->map.collect)
			mlx_close_window(game->mlx);
	}
}
```

**Parameters**:
- `t_game *game`: A pointer to the game structure containing the current state of the game, including the map and collectible count.
- `int y`: The vertical position of the player character.
- `int x`: The horizontal position of the player character.

**Functionality**:
- Checks if the tile at the player's current position `(y / IMG_W, x / IMG_H)` is the exit ('E').
- If the exit is reached:
  - Verifies if the player has collected all the required items (`game->count` equals `game->map.collect`).
  - If all items are collected, it calls `mlx_close_window` to close the game window and end the game.

<br>

## Main
### [so_long](src/so_long.c)

The `so_long` or `main` function serves as the entry point for the game application. It initializes the game, processes command-line arguments, and sets up the graphical interface.

```c
int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc, argv);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd < 0 || game.fd == 0)
		ft_error("Failed to open file");
	init_value(&game);
	map_parser(&game);
	if (map_checker(&game) == 0)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, true);
		game.mlx = mlx_init(IMG_W * game.map.columns, \
				IMG_H * game.map.rows, "so_long", true);
		if (!game.mlx)
		{
			ft_error_clean("Fail initializing MLX", &game);
			return (1);
		}
		init_graphics(&game);
		mlx_key_hook(game.mlx, &my_key_hook, &game.mlx);
		mlx_loop(game.mlx);
	}
	clean_up(&game);
	return (0);
}
```


**Parameters**:
- `int argc`: The number of command-line arguments passed to the program.
- `char **argv`: An array of strings representing the command-line arguments.

**Functionality**:
- Calls `check_args` to validate the command-line arguments.
- Attempts to open the specified map file using `open`. If the file fails to open, it triggers an error message using `ft_error`.
- Initializes the game structure by calling `init_value`.
- Parses the map from the file with `map_parser`.
- Checks the validity of the map using `map_checker`. If the map is valid (returns 0):
  - Sets the MLX image stretching setting to true.
  - Initializes the MLX graphical interface, creating a window based on the map dimensions. If initialization fails, it calls `ft_error_clean` to clean up and return an error.
  - Initializes the graphical elements by calling `init_graphics`.
  - Sets up a key hook with `mlx_key_hook` to handle player input and starts the MLX event loop with `mlx_loop`.
- After the event loop ends, it calls `clean_up` to free resources and clean up the game state.
- Returns 0 to indicate successful completion of the program.
