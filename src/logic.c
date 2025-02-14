/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordi <jordi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:12:00 by antandre          #+#    #+#             */
/*   Updated: 2025/02/14 23:39:48 by jordi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	del_collect(t_game *game, int y, int x)
{
	int	i;
	int	collects;

	i = 0;
	collects = game->map.collect;
	while (i < collects)
	{
		if (((game->img->collect->instances[i].y == y)
				&& (game->img->collect->instances[i].x == x))
			&& (game->img->collect->instances[i].enabled == true))
		{
			collects--;
			game->img->collect->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	pick_collect(t_game *game, int y, int x)
{
	if (game->map.arr[y / IMG_W][x / IMG_H] == 'C')
	{
		del_collect(game, y, x);
		game->map.arr[y / IMG_W][x / IMG_H] = '0';
		game->count++;
		if (game->count == game->map.collect)
			game->img->exit1->instances->enabled = false;
	}
}

void	finish_game(t_game *game, int y, int x)
{
	if (game->map.arr[y / IMG_W][x / IMG_H] == 'E')
	{
		if (game->count == game->map.collect)
			mlx_close_window(game->mlx);
	}
}
