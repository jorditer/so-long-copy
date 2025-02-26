/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrada <jterrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:18:26 by jordi             #+#    #+#             */
/*   Updated: 2025/02/15 11:46:17 by jterrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_calloc(t_game *game)
{
	if (!game->map.arr)
	{
		game->map.arr = ft_calloc(270, sizeof(char *));
		if (!game->map.arr)
			ft_error_clean("Error: Memory allocation for map failed.", game);
	}
}

// if == 0 to only check the first row
static void	map_len(t_game *game, char *line, int i)
{
	int	len;

	len = line_len(line);
	if (i == 0)
		game->map.columns = len;
	else if (len != game->map.columns)
		ft_error_clean("Error: Map must be rectangular", game);
	if (len >= MAP_W / IMG_W)
		ft_error_clean("Error: Map file too long.", game);
	return ;
}

void	map_parser(t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(game->fd);
	if (line == NULL)
		ft_error_clean("Error: Map file is empty.", game);
	i = 0;
	while (line && (line[0] != '\n'))
	{
		if (i >= MAP_H / IMG_H)
			ft_error_clean("Error: Map file too high.", game);
		if (game->map.arr == NULL)
			map_calloc(game);
		game->map.arr[i] = malloc(sizeof(char) * (line_len(line) + 1));
		if (!game->map.arr[i])
			ft_error_clean("Error: Error allocating map rows", game);
		map_len(game, line, i);
		ft_strlcpy(game->map.arr[i], line, game->map.columns + 1);
		i++;
		free(line);
		line = get_next_line(game->fd);
	}
	game->map.rows = i;
	free(line);
	close(game->fd);
}
