/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:54:01 by antandre          #+#    #+#             */
/*   Updated: 2024/09/29 16:43:34 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(t_game *game)
{
	size_t	len;
	int		i;

	if (!game->map.array || !game->map.array[0])
		ft_error("Map is empty or invalid.");
	len = ft_strlen(game->map.array[0]);
	i = 1;
	while (game->map.array[i])
	{
		if (ft_strlen(game->map.array[i]) != len)
			ft_error("Map is not rectangular.");
		i++;
	}
	return (0);
}

static int	is_surrounded_by_walls(t_game *game)
{
	int	i;
	int	last_row;

	if (!game->map.array || !game->map.array[0])
		ft_error("Map is empty or invalid.");
	last_row = 0;
	while (game->map.array[last_row])
		last_row++;
	last_row--;
	i = 0;
	while (game->map.array[0][i] && game->map.array[last_row][i])
	{
		if (game->map.array[0][i] != '1' || game->map.array[last_row][i] != '1')
			ft_error("Top or bottom row not enclosed by walls.");
		i++;
	}
	i = 0;
	while (game->map.array[i])
	{
		if (game->map.array[i][0] != '1'
				|| game->map.array[i][ft_strlen(game->map.array[i]) - 1] != '1')
			ft_error("Left or right not enclosed by walls.");
		i++;
	}
	return (0);
}

static void	invalid_components(t_game *game, int i, int j)
{
	if (game->map.array[i][j] != 'E' && game->map.array[i][j] != 'P'
			&& game->map.array[i][j] != 'C' && game->map.array[i][j] != 'E'
			&& game->map.array[i][j] != '1' && game->map.array[i][j] != '0')
		ft_error("Invalid components.");
}

static int	validate_map_components(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j])
		{
			//Guardar posiciones (x,y)
			if (game->map.array[i][j] == 'E')
				game->map.exit++;
			if (game->map.array[i][j] == 'P')
				game->map.player++;
			if (game->map.array[i][j] == 'C')
				game->map.collectible++;
			invalid_components(game, i, j);
			j++;
		}
		i++;
	}
	if (game->map.exit != 1 || game->map.player != 1
		|| game->map.collectible < 1)
		ft_error("Invalid number of components.");
	return (0);
}

int	map_checker(t_game *game)
{
	if (is_rectangular(game) == 1)
		return (1);
	if (is_surrounded_by_walls(game) == 1)
		return (1);
	if (validate_map_components(game) == 1)
		return (1);
	//validar pathfinding
	return (0);
}
