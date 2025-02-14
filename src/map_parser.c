/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordi <jordi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:54:55 by antandre          #+#    #+#             */
/*   Updated: 2025/02/14 22:45:05 by jordi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_calloc(t_game *game_instance)
{
	if (!game_instance->map.array)
	{
		game_instance->map.array = ft_calloc(270, sizeof(char *));
		if (!game_instance->map.array)
			ft_error_clean("Memmory allocation for map failed.", game_instance);
	}
}

static void	map_len(t_game *game_instance, char *line, int i)
{
	int	len;

	len = line_len(line);
	if (i == 0)
		game_instance->map.columns = len;
	if (len >= MAP_WIDTH / IMG_W)
		ft_error_clean("Map file too long.", game_instance);
	return ;
}

void	map_parser(t_game *game_instance)
{
	char	*line;
	int		i;

	line = get_next_line(game_instance->fd);
	if (line == NULL)
		ft_error_clean("Map file is empty.", game_instance);
	i = 0;
	while (line && (line[0] != '\n'))
	{
		if (i >= MAP_HEIGHT / IMG_H)
			ft_error_clean("Map file too high.", game_instance);
		if (game_instance->map.array == NULL)
			map_calloc(game_instance);
		game_instance->map.array[i] = malloc(sizeof(char) * (line_len(line) + 1));
		if (!game_instance->map.array[i])
			ft_error_clean("Error allocating map rows", game_instance);
		map_len(game_instance, line, i);
		ft_strlcpy(game_instance->map.array[i], line, game_instance->map.columns + 1);
		i++;
		free(line);
		line = get_next_line(game_instance->fd);
	}
	game_instance->map.rows = i;
	free(line);
	close(game_instance->fd);
}
