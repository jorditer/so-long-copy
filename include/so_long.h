/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:32:25 by antandre          #+#    #+#             */
/*   Updated: 2024/09/29 18:10:46 by antandre         ###   ########.fr       */
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

/* STRUCTS */

typedef struct s_coord
{
	mlx_image_t	*image;
	int			x;
	int			y;
}				t_coord;

typedef struct s_img
{
	mlx_image_t	*floor[2];
	mlx_image_t	*wall;
	t_coord		exit;
	t_coord		player;
	t_coord		collect[100];
}				t_img;

typedef struct s_map
{
	char	**array;
	char	**info;
	int		columns;
	int		rows;
	int		collectible;
	int		player;
	int		exit;
	int		walls;
	int		floor;
}				t_map;

typedef struct s_position
{
	int					x;
	int					y;
	unsigned int		move;
}				t_position;

typedef struct s_game
{
	mlx_t		*mlx;
	int			fd;
	t_img		img;
	t_map		map;
	t_position	position;
	int			count;
	int			finish_game;
}				t_game;

/* FUNCTIONS */

void	ft_error(char *msg);
void	map_parser(t_game *game);
int	map_checker(t_game *game);
void	init_value(t_game *game);
int	line_len(char *str);
void	free_map(char *msg, t_game *game);
int	pathfinding(t_game *game);
int	init_graphics(t_game *game);

#endif
