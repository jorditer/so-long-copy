/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordi <jordi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:20:42 by antandre          #+#    #+#             */
/*   Updated: 2025/02/14 23:23:07 by jordi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game_instance, int y, int x)
{
	if (game_instance->map.array[(y - IMG_W) / IMG_W][x / IMG_H] != '1')
	{
		game_instance->img->pnj->instances[0].y -= IMG_W;
		game_instance->position.move++;
		ft_printf("[MOVEMENT: %i]\n", game_instance->position.move);
	}
}

static void	move_down(t_game *game_instance, int y, int x)
{
	if (game_instance->map.array[(y + IMG_W) / IMG_W][x / IMG_H] != '1')
	{
		game_instance->img->pnj->instances[0].y += IMG_W;
		game_instance->position.move++;
		ft_printf("[MOVEMENT: %i]\n", game_instance->position.move);
	}
}

static void	move_right(t_game *game_instance, int y, int x)
{
	if (game_instance->map.array[y / IMG_W][(x + IMG_H) / IMG_H] != '1')
	{
		game_instance->img->pnj->instances[0].x += IMG_H;
		game_instance->position.move++;
		ft_printf("[MOVEMENT: %i]\n", game_instance->position.move);
	}
}

static void	move_left(t_game *game_instance, int y, int x)
{
	if (game_instance->map.array[y / IMG_W][(x - IMG_H) / IMG_H] != '1')
	{
		game_instance->img->pnj->instances[0].x -= IMG_H;
		game_instance->position.move++;
		ft_printf("[MOVEMENT: %i]\n", game_instance->position.move);
	}
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game_instance;
	int		*y;
	int		*x;

	game_instance = param;
	y = &game_instance->img->pnj->instances[0].y;
	x = &game_instance->img->pnj->instances[0].x;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
		move_up(game_instance, *y, *x);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		move_right(game_instance, *y, *x);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS))
		move_down(game_instance, *y, *x);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
		move_left(game_instance, *y, *x);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game_instance->mlx);
	pick_collect(game_instance, *y, *x);
	finish_game(game_instance, *y, *x);
}
