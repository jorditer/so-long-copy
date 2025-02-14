/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordi <jordi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:54:01 by antandre          #+#    #+#             */
/*   Updated: 2025/02/14 23:39:46 by jordi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(t_game *game)
{
	size_t	len;
	int		i;

	if (!game->map.arr || !game->map.arr[0])
		ft_error("Error: Map is empty or invalid.");
	len = ft_strlen(game->map.arr[0]);
	i = 1;
	while (game->map.arr[i])
	{
		if (ft_strlen(game->map.arr[i]) != len)
			ft_error("Error: Map is not rectangular.");
		i++;
	}
	return (0);
}

static int	is_surrounded_by_walls(t_game *game)
{
	int	i;
	int	last;

	if (!game->map.arr || !game->map.arr[0])
		ft_error("Error: Map is empty or invalid.");
	last = 0;
	while (game->map.arr[last])
		last++;
	last--;
	i = 0;
	while (game->map.arr[0][i] && game->map.arr[last][i])
	{
		if (game->map.arr[0][i] != '1' || game->map.arr[last][i] != '1')
			ft_error("Error: Top or bottom row not enclosed by walls.");
		i++;
	}
	i = 0;
	while (game->map.arr[i])
	{
		if (game->map.arr[i][0] != '1'
				|| game->map.arr[i][ft_strlen(game->map.arr[i]) - 1] != '1')
			ft_error("Error: Left or right not enclosed by walls.");
		i++;
	}
	return (0);
}

static void	invalid_components(t_game *game, int i, int j)
{
	if (game->map.arr[i][j] != 'E' && game->map.arr[i][j] != 'P'
			&& game->map.arr[i][j] != 'C' && game->map.arr[i][j] != 'E'
			&& game->map.arr[i][j] != '1' && game->map.arr[i][j] != '0')
		ft_error("Error: Invalid components.");
	if (game->map.arr[i][j] == 'P')
	{
		game->map.player++;
		game->position.x = j;
		game->position.y = i;
	}
}

static int	validate_map_components(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.arr[i])
	{
		j = 0;
		while (game->map.arr[i][j])
		{
			if (game->map.arr[i][j] == 'E')
				game->map.exit++;
			if (game->map.arr[i][j] == 'C')
				game->map.collect++;
			invalid_components(game, i, j);
			j++;
		}
		i++;
	}
	if (game->map.exit != 1 || game->map.player != 1 || game->map.collect < 1)
		ft_error("Error: Invalid number of components.");
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
	if (pathfinding(game) == 1)
		return (1);
	return (0);
}
