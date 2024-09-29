/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:47:21 by antandre          #+#    #+#             */
/*   Updated: 2024/09/29 18:34:24 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_map(t_game *game)
{
	int	i;
	
	if (!game->map.info)
	{
		game->map.info = (char **)malloc(sizeof(char *) * (game->map.rows + 1));
		if (!game->map.info)
			free_map("Memory allocation failed for map rows info.", game);
		i = 0;
		while (i < game->map.rows)
		{
			game->map.info[i] = malloc(sizeof(char) * (game->map.columns + 1));
			if (!game->map.info[i])
				free_map("Memory allocation failed for map columns info.", game);
			ft_strlcpy(game->map.info[i], game->map.array[i], game->map.columns + 1);
			i++;
		}
		game->map.info[i] = NULL;
	}
}

void	flood_fill(t_game *game, int x, int y, int *collectibles, int *exit_found)
{
	if (x < 0 || y < 0 || x >= game->map.columns || y >= game->map.rows || 
			game->map.info[y][x] == '1' || game->map.info[y][x] == 'V')
		return ;
	if (game->map.info[y][x] == 'C')
		(*collectibles)--;
	if (game->map.info[y][x] == 'E')
		*exit_found = 1;
	game->map.info[y][x] = 'V';
	flood_fill(game, x + 1, y, collectibles, exit_found);
	flood_fill(game, x - 1, y, collectibles, exit_found);
	flood_fill(game, x, y + 1, collectibles, exit_found);
	flood_fill(game, x, y - 1, collectibles, exit_found);
}

int	pathfinding(t_game *game)
{
	int	collectibles;
	int	exit_found;

	collectibles = game->map.collectible;
	exit_found = 0;
	copy_map(game);
	flood_fill(game, game->position.x, game->position.y, &collectibles, &exit_found);
	if (collectibles > 0 || !exit_found)
		ft_error("Not all collectibles or exit are reachable.");
	return (0);
}
