/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrada <jterrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:17:56 by jterrada          #+#    #+#             */
/*   Updated: 2025/02/24 17:17:57 by jterrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game, int y, int x)
{
	if (game->map.arr[(y - IMG_W) / IMG_W][x / IMG_H] != '1')
	{
		game->img->pnj->instances[0].y -= IMG_W;
		game->position.move++;
		ft_printf("[MOVEMENT: %i]\n", game->position.move);
	}
}

static void	move_down(t_game *game, int y, int x)
{
	if (game->map.arr[(y + IMG_W) / IMG_W][x / IMG_H] != '1')
	{
		game->img->pnj->instances[0].y += IMG_W;
		game->position.move++;
		ft_printf("[MOVEMENT: %i]\n", game->position.move);
	}
}

static void	move_right(t_game *game, int y, int x)
{
	if (game->map.arr[y / IMG_W][(x + IMG_H) / IMG_H] != '1')
	{
		game->img->pnj->instances[0].x += IMG_H;
		game->position.move++;
		ft_printf("[MOVEMENT: %i]\n", game->position.move);
	}
}

static void	move_left(t_game *game, int y, int x)
{
	if (game->map.arr[y / IMG_W][(x - IMG_H) / IMG_H] != '1')
	{
		game->img->pnj->instances[0].x -= IMG_H;
		game->position.move++;
		ft_printf("[MOVEMENT: %i]\n", game->position.move);
	}
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		*y;
	int		*x;

	game = param;
	y = &game->img->pnj->instances[0].y;
	x = &game->img->pnj->instances[0].x;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS))
		move_up(game, *y, *x);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS))
		move_right(game, *y, *x);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS))
		move_down(game, *y, *x);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS))
		move_left(game, *y, *x);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	pick_collect(game, *y, *x);
	finish_game(game, *y, *x);
}
