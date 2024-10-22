/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:18:58 by antandre          #+#    #+#             */
/*   Updated: 2024/10/22 19:45:43 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *msg)
{
	ft_printf("[ERROR] %s\n", msg);
	exit(1);
}

void	ft_error_clean(char *msg, t_game *game)
{
	ft_printf("[ERROR] %s\n", msg);
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
	free_map_array(game->map.array, game->map.columns);
	if (game->map.info != NULL)
		free_map_info(game->map.info);
}
