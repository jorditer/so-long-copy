/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordi <jordi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:47:21 by antandre          #+#    #+#             */
/*   Updated: 2025/02/14 22:45:11 by jordi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_map(t_game *game_instance)
{
	int	i;

	if (!game_instance->map.info)
	{
		game_instance->map.info = (char **)malloc(sizeof(char *) * (game_instance->map.rows + 1));
		if (!game_instance->map.info)
			ft_error_clean("Allocation failed for map rows info.", game_instance);
		i = 0;
		while (i < game_instance->map.rows)
		{
			game_instance->map.info[i] = malloc(sizeof(char) * (game_instance->map.columns + 1));
			if (!game_instance->map.info[i])
				ft_error_clean("Allocation failed for map columns info.", game_instance);
			ft_strlcpy(game_instance->map.info[i], game_instance->map.array[i], \
					game_instance->map.columns + 1);
			i++;
		}
		game_instance->map.info[i] = NULL;
	}
}

void	flood_fill(t_game *game_instance, int x, int y, int *collect)
{
	if (x < 0 || y < 0 || x >= game_instance->map.columns || y >= game_instance->map.rows
		|| game_instance->map.info[y][x] == '1' || game_instance->map.info[y][x] == 'V')
		return ;
	if (game_instance->map.info[y][x] == 'C')
		(*collect)--;
	if (game_instance->map.info[y][x] == 'E')
		game_instance->map.exit_found = 1;
	game_instance->map.info[y][x] = 'V';
	flood_fill(game_instance, x + 1, y, collect);
	flood_fill(game_instance, x - 1, y, collect);
	flood_fill(game_instance, x, y + 1, collect);
	flood_fill(game_instance, x, y - 1, collect);
}

int	pathfinding(t_game *game_instance)
{
	int	collect;

	collect = game_instance->map.collect;
	copy_map(game_instance);
	flood_fill(game_instance, game_instance->position.x, game_instance->position.y, &collect);
	if (collect > 0 || !game_instance->map.exit_found)
		ft_error("Not all collectibles or exit are reachable.");
	return (0);
}
