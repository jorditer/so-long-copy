/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrada <jterrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:18:56 by jterrada          #+#    #+#             */
/*   Updated: 2025/02/24 17:18:57 by jterrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_map(t_game *game)
{
	int	i;

	if (!game->map.map_copy)
	{
		game->map.map_copy = malloc(sizeof(char *) * (game->map.rows + 1));
		if (!game->map.map_copy)
			ft_error_clean("Error: Allocation failed for map rows info.", game);
		i = 0;
		while (i < game->map.rows)
		{
			game->map.map_copy[i] = malloc(1 * (game->map.columns + 1));
			if (!game->map.map_copy[i])
				ft_error_clean("Error: Allocation failed for columns", game);
			ft_strlcpy(game->map.map_copy[i], game->map.arr[i], \
					game->map.columns + 1);
			i++;
		}
		game->map.map_copy[i] = NULL;
	}
}

void	flood_fill(t_game *game, int x, int y, int *collect)
{
	if (x < 0 || y < 0 || x >= game->map.columns || y >= game->map.rows
		|| game->map.map_copy[y][x] == '1' || game->map.map_copy[y][x] == 'V')
		return ;
	if (game->map.map_copy[y][x] == 'C')
		(*collect)--;
	if (game->map.map_copy[y][x] == 'E')
		game->map.exit_found = 1;
	game->map.map_copy[y][x] = 'V';
	flood_fill(game, x + 1, y, collect);
	flood_fill(game, x - 1, y, collect);
	flood_fill(game, x, y + 1, collect);
	flood_fill(game, x, y - 1, collect);
}

int	pathfinding(t_game *game)
{
	int	collect;

	collect = game->map.collect;
	copy_map(game);
	flood_fill(game, game->position.x, game->position.y, &collect);
	if (collect > 0 || !game->map.exit_found)
		ft_error("Error: Not all collectibles or exit are reachable.");
	return (0);
}
