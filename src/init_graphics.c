/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:44:50 by antandre          #+#    #+#             */
/*   Updated: 2024/10/08 18:28:55 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_textures(t_game *game)
{
	game->txt = ft_calloc(1, sizeof(t_txt));
	if (!game->txt)
		ft_error("Failled allocation for textures");
	game->txt->floor[0] = mlx_load_png("./assets/floor1.png");
	game->txt->floor[1] = mlx_load_png("./assets/floor2.png");
	game->txt->wall = mlx_load_png("./assets/wall.png");
	game->txt->exit[0] = mlx_load_png("./assets/exit1.png");
	game->txt->exit[1] = mlx_load_png("./assets/exit2.png");
	game->txt->pnj[0] = mlx_load_png("./assets/p_up.png");
	game->txt->pnj[1] = mlx_load_png("./assets/p_down.png");
	game->txt->pnj[2] = mlx_load_png("./assets/p_l.png");
	game->txt->pnj[3] = mlx_load_png("./assets/p_r.png");
	game->txt->collect = mlx_load_png("./assets/collect.png");
	if (!game->txt->floor[0] || !game->txt->floor[1]
		|| !game->txt->wall || !game->txt->exit[0]
		|| !game->txt->exit[1] || !game->txt->pnj[0]
		|| !game->txt->pnj[1] || !game->txt->pnj[2]
		|| !game->txt->pnj[3] || !game->txt->collect)
	{
		delete_textures(game);
		ft_error("Failed loading textures");
	}
	return (0);
}

static int	init_images(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_img));
	if (!game->img)
		ft_error("Failed allocation for images");
	game->img->floor[0] = mlx_texture_to_image(game->mlx, game->txt->floor[0]);
	game->img->floor[1] = mlx_texture_to_image(game->mlx, game->txt->floor[1]);
	game->img->wall = mlx_texture_to_image(game->mlx, game->txt->wall);
	game->img->exit[0] = mlx_texture_to_image(game->mlx, game->txt->exit[0]);
	game->img->exit[1] = mlx_texture_to_image(game->mlx, game->txt->exit[1]);
	game->img->pnj[0] = mlx_texture_to_image(game->mlx, game->txt->pnj[0]);
	game->img->pnj[1] = mlx_texture_to_image(game->mlx, game->txt->pnj[1]);
	game->img->pnj[2] = mlx_texture_to_image(game->mlx, game->txt->pnj[2]);
	game->img->pnj[3] = mlx_texture_to_image(game->mlx, game->txt->pnj[3]);
	game->img->collect = mlx_texture_to_image(game->mlx, game->txt->collect);
	if (!game->img->floor[0] || !game->img->floor[1] || !game->img->wall
		|| !game->img->exit[0] || !game->img->exit[1] || !game->img->pnj[0]
		|| !game->img->pnj[1] || !game->img->pnj[2]
		|| !game->img->pnj[3] || !game->img->collect)
	{
		delete_textures(game);
		delete_images(game);
		ft_error("Failed creating images from textures");
	}
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
			mlx_image_to_window(game->mlx, game->img->floor[0], \
					x * IMG_WIDTH, y * IMG_HEIGHT);
			if (game->map.array[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img->wall, \
						x * IMG_WIDTH, y * IMG_HEIGHT);
			if (game->map.array[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img->exit[0], \
						x * IMG_WIDTH, y * IMG_HEIGHT);
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
						x * IMG_WIDTH, y * IMG_HEIGHT);
			if (game->map.array[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->img->pnj[1], \
						x * IMG_WIDTH, y * IMG_HEIGHT);
			x++;
		}
		y++;
	}
}

int	init_graphics(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(IMG_WIDTH * game->map.columns, \
			IMG_HEIGHT * game->map.rows, "so_long", true);
	if (!game->mlx)
		free_map("Fail initializing MLX", game);
	init_textures(game);
	init_images(game);
	draw_map(game);
	draw_items(game);
	mlx_loop(game->mlx);
	delete_images(game);
	//Optional, terminate will clean up any leftover images (not textures!)
	//CLEAN UP EVERYTHING
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
