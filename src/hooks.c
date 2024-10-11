/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:20:42 by antandre          #+#    #+#             */
/*   Updated: 2024/10/11 13:40:10 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game, int y, int x)
{
	if (game->map.array[(y - 50) / 50][x / 50] != '1')
	{
		game->img->pnj->instances[0].y -= 50;
		game->count++;
		ft_printf("MOVES: %i\n", game->count);
	}
}

static void	move_down(t_game *game, int y, int x)
{
	if (game->map.array[(y + 50) / 50][x / 50] != '1')
	{
		game->img->pnj->instances[0].y += 50;
		game->count++;
		ft_printf("MOVES: %i\n", game->count);
	}
}

static void	move_right(t_game *game, int y, int x)
{
	if (game->map.array[y / 50][(x + 50) / 50] != '1')
	{
		game->img->pnj->instances[0].x += 50;
		game->count++;
		ft_printf("MOVES: %i\n", game->count);
	}
}

static void	move_left(t_game *game, int y, int x)
{
	if (game->map.array[y / 50][(x - 50) / 50] != '1')
	{
		game->img->pnj->instances[0].x -= 50;
		game->count++;
		ft_printf("MOVES: %i\n", game->count);
	}
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int	*y;
	int	*x;
	
	game = param;
	y = &game->img->pnj->instances[0].y;
	x = &game->img->pnj->instances[0].x;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		move_up(game, *y, *x);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE))
		move_right(game, *y, *x);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE))
		move_down(game, *y, *x);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE))
		move_left(game, *y, *x);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
}
