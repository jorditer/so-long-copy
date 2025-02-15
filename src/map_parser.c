/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordi <jordi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:18:26 by jordi             #+#    #+#             */
/*   Updated: 2025/02/15 00:18:30 by jordi            ###   ########.fr       */
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

static void	map_len(t_game *game, char *line, int i)
{
	int	len;

	len = line_len(line);
	if (i == 0)
		game->map.columns = len;
	if (len >= MAP_WIDTH / IMG_W)
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
		if (i >= MAP_HEIGHT / IMG_H)
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
