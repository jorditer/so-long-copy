/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:06:09 by antandre          #+#    #+#             */
/*   Updated: 2024/10/22 20:50:04 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (i);
}

void	check_args(int argc, char **argv)
{
	int	map_len;

	if (argc != 2)
		ft_error("Invalid number of arguments.");
	map_len = ft_strlen(argv[1]);
	if (ft_strnstr(&argv[1][map_len - 4], ".ber", 4) == NULL)
		ft_error("Invalid map extension.");
}

void	init_value(t_game *game)
{
	game->position.x = 0;
	game->position.y = 0;
	game->position.move = 0;
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.collect = 0;
	game->map.exit = 0;
	game->map.player = 0;
	game->map.walls = 0;
	game->map.floor = 0;
	game->map.info = NULL;
	game->map.exit_found = 0;
	game->count = 0;
	game->finish_game = 0;
	game->map.array = NULL;
	game->txt = NULL;
	game->img = NULL;
	game->mlx = NULL;
}
