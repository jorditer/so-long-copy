/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrada <jterrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:18:04 by jterrada          #+#    #+#             */
/*   Updated: 2025/02/24 17:18:06 by jterrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(const char *msg)
{
	ft_printf("ERROR %s\n", msg);
	exit(1);
}

void	ft_error_clean(const char *msg, t_game *game)
{
	ft_printf("ERROR %s\n", msg);
	if (game->mlx)
		mlx_terminate(game->mlx);
	clean_up(game);
	exit(1);
}

static void	free_map_array(char **map, int columns)
{
	int	i;

	if (!map || !*map)
		ft_error("Map data not found or invalid.");
	i = 0;
	while (i < columns && map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	free_map_info(char **vector)
{
	int	i;

	if (!vector || !*vector)
		ft_error("Invalid map data.");
	i = 0;
	while (vector[i] != NULL)
	{
		free(vector[i]);
		i++;
	}
	free(vector);
}

void	free_map(t_game *game)
{
	free_map_array(game->map.arr, game->map.columns);
	if (game->map.map_copy != NULL)
		free_map_info(game->map.map_copy);
}
