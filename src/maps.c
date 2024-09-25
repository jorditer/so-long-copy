/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:54:55 by antandre          #+#    #+#             */
/*   Updated: 2024/09/25 13:26:08 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_game *game)
{
	char	*line;
	int		i;

	game->map.calloc = ft_calloc(1024, sizeof(char *));
	if (!game->map.calloc)
		ft_error("Memmory allocation for map failed.");
	i = 0;
	line = get_next_line(game->fd);
	if (line == NULL)
		ft_error("Map file is empty.");
	while (line && line[0] != '\n')
	{
		//Strlcpy line on game->map.calloc[i]
	}
	close(game.fd);
}
