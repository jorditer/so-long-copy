/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:06:09 by antandre          #+#    #+#             */
/*   Updated: 2024/10/22 18:27:00 by antandre         ###   ########.fr       */
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

void	clean_up(t_game *game)
{
	delete_images(game);
	delete_textures(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map.array || game->map.info)
		free_map(game);
	if (game->fd > 0)
    close(game->fd);
}
