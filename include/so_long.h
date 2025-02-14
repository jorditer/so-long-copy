/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordi <jordi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:32:25 by antandre          #+#    #+#             */
/*   Updated: 2025/02/14 23:18:27 by jordi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>

# include "../lib/Libft/include/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define MAP_HEIGHT 2500
# define MAP_WIDTH  2500
# define IMG_H 32
# define IMG_W 32

typedef struct s_txt
{
	mlx_texture_t	*floor;
	mlx_texture_t	*collect;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit1;
	mlx_texture_t	*exit2;
	mlx_texture_t	*pnj;
}							t_txt;

typedef struct s_img
{
	mlx_image_t	*floor;
	mlx_image_t	*collect;
	mlx_image_t	*wall;
	mlx_image_t	*exit1;
	mlx_image_t	*exit2;
	mlx_image_t	*pnj;
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

// errors.c
void	ft_error(char *msg);
void	ft_error_clean(char *msg, t_game *game);
void	free_map(t_game *game);
// parsing.c
void	map_parser(t_game *game);
int		map_checker(t_game *game);
int		pathfinding(t_game *game);
// graphic.s
void	init_graphics(t_game *game);
void	remove_textures(t_game *game);
void	remove_images(t_game *game);
// utils.c
void	init_value(t_game *game);
int		line_len(char *str);
void	check_args(int argc, char **argv);
void	clean_up(t_game *game);
// logic.c
void	my_key_hook(mlx_key_data_t keydata, void *param);
void	pick_collect(t_game *game, int y, int x);
void	finish_game(t_game *game, int y, int x);

#endif
