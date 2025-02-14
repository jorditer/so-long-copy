/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordi <jordi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:12:00 by antandre          #+#    #+#             */
/*   Updated: 2025/02/14 23:16:45 by jordi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	del_collect(t_game *game_instance, int y, int x)
{
	int	i;
	int	collects;

	i = 0;
	collects = game_instance->map.collect;
	while (i < collects)
	{
		if (((game_instance->img->collect->instances[i].y == y)
				&& (game_instance->img->collect->instances[i].x == x))
			&& (game_instance->img->collect->instances[i].enabled == true))
		{
			collects--;
			game_instance->img->collect->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	pick_collect(t_game *game_instance, int y, int x)
{
	if (game_instance->map.array[y / IMG_W][x / IMG_H] == 'C')
	{
		del_collect(game_instance, y, x);
		game_instance->map.array[y / IMG_W][x / IMG_H] = '0';
		game_instance->count++;
		if (game_instance->count == game_instance->map.collect)
			game_instance->img->exit1->instances->enabled = false;
	}
}

void	finish_game(t_game *game_instance, int y, int x)
{
	if (game_instance->map.array[y / IMG_W][x / IMG_H] == 'E')
	{
		if (game_instance->count == game_instance->map.collect)
			mlx_close_window(game_instance->mlx);
	}
}
