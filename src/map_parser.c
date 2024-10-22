/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:54:55 by antandre          #+#    #+#             */
/*   Updated: 2024/10/22 18:57:14 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_calloc(t_game *game)
{
	if (!game->map.array)
	{
		game->map.array = ft_calloc(270, sizeof(char *));
		if (!game->map.array)
			ft_error_clean("Memmory allocation for map failed.", game);
	}
}

static void	map_len(t_game *game, char *line, int i)
{
	int	len;

	len = line_len(line);
	if (i == 0)
		game->map.columns = len;
	if (len >= MAP_WIDTH / IMG_W)
		ft_error_clean("Map file too long.", game);
	return ;
}

void	map_parser(t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(game->fd);
	if (line == NULL)
		ft_error_clean("Map file is empty.", game);
	i = 0;
	while (line && (line[0] != '\n'))
	{
		if (i >= MAP_HEIGHT / IMG_H)
			ft_error_clean("Map file too high.", game);
		if (game->map.array == NULL)
			map_calloc(game);
		game->map.array[i] = malloc(sizeof(char) * (line_len(line) + 1));
		if (!game->map.array[i])
			ft_error_clean("Error allocating map rows", game);
		map_len(game, line, i);
		ft_strlcpy(game->map.array[i], line, game->map.columns + 1);
		i++;
		free(line);
		line = get_next_line(game->fd);
	}
	game->map.rows = i;
	free(line);
	close(game->fd);
}
