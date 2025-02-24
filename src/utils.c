/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrada <jterrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:18:25 by jterrada          #+#    #+#             */
/*   Updated: 2025/02/24 17:18:27 by jterrada         ###   ########.fr       */
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
		ft_error("Error: Invalid number of arguments.");
	map_len = ft_strlen(argv[1]);
	if (ft_strnstr(&argv[1][map_len - 4], ".ber", 4) == NULL)
		ft_error("Error: Invalid map extension.");
}

void	init_value(t_game *game_instance)
{
	game_instance->position.x = 0;
	game_instance->position.y = 0;
	game_instance->position.move = 0;
	game_instance->map.rows = 0;
	game_instance->map.columns = 0;
	game_instance->map.collect = 0;
	game_instance->map.exit = 0;
	game_instance->map.player = 0;
	game_instance->map.walls = 0;
	game_instance->map.floor = 0;
	game_instance->map.map_copy = NULL;
	game_instance->map.exit_found = 0;
	game_instance->count = 0;
	game_instance->finish_game = 0;
	game_instance->map.arr = NULL;
	game_instance->txt = NULL;
	game_instance->img = NULL;
	game_instance->mlx = NULL;
}
