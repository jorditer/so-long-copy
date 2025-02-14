/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordi <jordi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:54:01 by antandre          #+#    #+#             */
/*   Updated: 2025/02/14 22:45:05 by jordi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(t_game *game_instance)
{
	size_t	len;
	int		i;

	if (!game_instance->map.array || !game_instance->map.array[0])
		ft_error("Map is empty or invalid.");
	len = ft_strlen(game_instance->map.array[0]);
	i = 1;
	while (game_instance->map.array[i])
	{
		if (ft_strlen(game_instance->map.array[i]) != len)
			ft_error("Map is not rectangular.");
		i++;
	}
	return (0);
}

static int	is_surrounded_by_walls(t_game *game_instance)
{
	int	i;
	int	last_row;

	if (!game_instance->map.array || !game_instance->map.array[0])
		ft_error("Map is empty or invalid.");
	last_row = 0;
	while (game_instance->map.array[last_row])
		last_row++;
	last_row--;
	i = 0;
	while (game_instance->map.array[0][i] && game_instance->map.array[last_row][i])
	{
		if (game_instance->map.array[0][i] != '1' || game_instance->map.array[last_row][i] != '1')
			ft_error("Top or bottom row not enclosed by walls.");
		i++;
	}
	i = 0;
	while (game_instance->map.array[i])
	{
		if (game_instance->map.array[i][0] != '1'
				|| game_instance->map.array[i][ft_strlen(game_instance->map.array[i]) - 1] != '1')
			ft_error("Left or right not enclosed by walls.");
		i++;
	}
	return (0);
}

static void	invalid_components(t_game *game_instance, int i, int j)
{
	if (game_instance->map.array[i][j] != 'E' && game_instance->map.array[i][j] != 'P'
			&& game_instance->map.array[i][j] != 'C' && game_instance->map.array[i][j] != 'E'
			&& game_instance->map.array[i][j] != '1' && game_instance->map.array[i][j] != '0')
		ft_error("Invalid components.");
	if (game_instance->map.array[i][j] == 'P')
	{
		game_instance->map.player++;
		game_instance->position.x = j;
		game_instance->position.y = i;
	}
}

static int	validate_map_components(t_game *game_instance)
{
	int	i;
	int	j;

	i = 0;
	while (game_instance->map.array[i])
	{
		j = 0;
		while (game_instance->map.array[i][j])
		{
			if (game_instance->map.array[i][j] == 'E')
				game_instance->map.exit++;
			if (game_instance->map.array[i][j] == 'C')
				game_instance->map.collect++;
			invalid_components(game_instance, i, j);
			j++;
		}
		i++;
	}
	if (game_instance->map.exit != 1 || game_instance->map.player != 1 || game_instance->map.collect < 1)
		ft_error("Invalid number of components.");
	return (0);
}

int	map_checker(t_game *game_instance)
{
	if (is_rectangular(game_instance) == 1)
		return (1);
	if (is_surrounded_by_walls(game_instance) == 1)
		return (1);
	if (validate_map_components(game_instance) == 1)
		return (1);
	if (pathfinding(game_instance) == 1)
		return (1);
	return (0);
}
