/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:20:42 by antandre          #+#    #+#             */
/*   Updated: 2024/10/22 14:49:12 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
