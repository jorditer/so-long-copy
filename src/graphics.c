/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:44:50 by antandre          #+#    #+#             */
/*   Updated: 2024/10/22 20:31:11 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!game->txt->floor || !game->txt->floor || !game->txt->wall 
			|| !game->txt->exit1 || !game->txt->exit2 || !game->txt->pnj
			|| !game->txt->collect)
		ft_error_clean("Failed loading textures", game);
	return (0);
}

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

void	init_graphics(t_game *game)
{
	init_textures(game);
	init_images(game);
	draw_map(game);
	draw_items(game);
}
