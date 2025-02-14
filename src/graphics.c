/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordi <jordi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:44:50 by antandre          #+#    #+#             */
/*   Updated: 2025/02/14 22:51:50 by jordi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_items(t_game *game_instance)
{
	int	x;
	int	y;

	y = 0;
	while (game_instance->map.array[y])
	{
		x = 0;
		while (game_instance->map.array[y][x])
		{
			if (game_instance->map.array[y][x] == 'C')
				mlx_image_to_window(game_instance->mlx, game_instance->img->collect, \
						x * IMG_W, y * IMG_H);
			if (game_instance->map.array[y][x] == 'P')
				mlx_image_to_window(game_instance->mlx, game_instance->img->pnj, \
						x * IMG_W, y * IMG_H);
			x++;
		}
		y++;
	}
}

static int	init_images(t_game *game_instance)
{
	game_instance->img = ft_calloc(1, sizeof(t_img));
	if (!game_instance->img)
		ft_error_clean("Failed allocation for images", game_instance);
	game_instance->img->floor = mlx_texture_to_image(game_instance->mlx, game_instance->txt->floor);
	game_instance->img->wall = mlx_texture_to_image(game_instance->mlx, game_instance->txt->wall);
	game_instance->img->exit1 = mlx_texture_to_image(game_instance->mlx, game_instance->txt->exit1);
	game_instance->img->exit2 = mlx_texture_to_image(game_instance->mlx, game_instance->txt->exit2);
	game_instance->img->pnj = mlx_texture_to_image(game_instance->mlx, game_instance->txt->pnj);
	game_instance->img->collect = mlx_texture_to_image(game_instance->mlx, game_instance->txt->collect);
	if (!game_instance->img->floor || !game_instance->img->wall || !game_instance->img->exit1
		|| !game_instance->img->exit2 || !game_instance->img->pnj || !game_instance->img->collect)
		ft_error_clean("Failed creating images from textures", game_instance);
	delete_textures(game_instance);
	return (0);
}

static int	init_textures(t_game *game_instance)
{
	game_instance->txt = ft_calloc(1, sizeof(t_txt));
	if (!game_instance->txt)
		ft_error_clean("Failled allocation for textures", game_instance);
	game_instance->txt->floor = mlx_load_png("./assets/floor1.png");
	game_instance->txt->wall = mlx_load_png("./assets/wall.png");
	game_instance->txt->exit1 = mlx_load_png("./assets/exit1.png");
	game_instance->txt->exit2 = mlx_load_png("./assets/exit2.png");
	game_instance->txt->pnj = mlx_load_png("./assets/pnj.png");
	game_instance->txt->collect = mlx_load_png("./assets/collect.png");
	if (!game_instance->txt->floor || !game_instance->txt->wall || !game_instance->txt->exit1
		|| !game_instance->txt->exit2 || !game_instance->txt->pnj || !game_instance->txt->collect)
		ft_error_clean("Failed loading textures", game_instance);
	return (0);
}

static void	draw_map(t_game *game_instance)
{
	int	x;
	int	y;

	y = 0;
	while (game_instance->map.array[y])
	{
		x = 0;
		while (game_instance->map.array[y][x])
		{
			mlx_image_to_window(game_instance->mlx, game_instance->img->floor, \
					x * IMG_W, y * IMG_H);
			if (game_instance->map.array[y][x] == '1')
				mlx_image_to_window(game_instance->mlx, game_instance->img->wall, \
						x * IMG_W, y * IMG_H);
			if (game_instance->map.array[y][x] == 'E')
			{
				mlx_image_to_window(game_instance->mlx, game_instance->img->exit2, \
						x * IMG_W, y * IMG_H);
				mlx_image_to_window(game_instance->mlx, game_instance->img->exit1, \
						x * IMG_W, y * IMG_H);
			}
			x++;
		}
		y++;
	}
}

void	init_graphics(t_game *game_instance)
{
	init_textures(game_instance);
	init_images(game_instance);
	draw_map(game_instance);
	draw_items(game_instance);
}
