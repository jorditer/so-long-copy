/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:32:25 by antandre          #+#    #+#             */
/*   Updated: 2024/10/22 19:49:02 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* HEADERS AND LIBRARIES */

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/Libft/include/libft.h"

/* VARIABLES */

# define MAP_WIDTH  7100
# define MAP_HEIGHT 7100
# define IMG_W 50
# define IMG_H 50

/* STRUCTS */

typedef struct s_txt
{
	mlx_texture_t	*floor[2];
	mlx_texture_t	*wall;
	mlx_texture_t	*exit[2];
	mlx_texture_t	*pnj;
	mlx_texture_t	*collect;
}							t_txt;

typedef struct s_img
{
	mlx_image_t	*floor[2];
	mlx_image_t	*wall;
	mlx_image_t	*exit[2];
	mlx_image_t	*pnj;
	mlx_image_t	*collect;
}				t_img;

typedef struct s_map
{
	char	**array;
	char	**info;
	int		columns;
	int		rows;
	int		collect;
	int		player;
	int		exit;
	int		walls;
	int		floor;
	int		exit_found;
}				t_map;

typedef struct s_position
{
	int					x;
	int					y;
	unsigned int		move;
}				t_position;

typedef struct s_game
{
	mlx_t						*mlx;
	int							fd;
	struct s_txt				*txt;
	struct s_img				*img;
	t_map						map;
	t_position					position;
	int							count;
	int							finish_game;
}				t_game;

/* FUNCTIONS */

// Errors
void	ft_error(char *msg);
void	ft_error_clean(char *msg, t_game *game);
void	free_map(t_game *game);
//Parsing
void	map_parser(t_game *game);
int		map_checker(t_game *game);
int		pathfinding(t_game *game);
//Graphics
void	init_graphics(t_game *game);
void	delete_textures(t_game *game);
void	delete_images(t_game *game);
// Utils
void	init_value(t_game *game);
int		line_len(char *str);
void	check_args(int argc, char **argv);
void	clean_up(t_game *game);
// Logic
void	my_key_hook(mlx_key_data_t keydata, void *param);
void	pick_collect(t_game *game, int y, int x);
void	finish_game(t_game *game, int y, int x);

#endif
