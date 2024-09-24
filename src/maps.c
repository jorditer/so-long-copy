/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:54:55 by antandre          #+#    #+#             */
/*   Updated: 2024/09/24 21:11:22 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parse_map(const char *file)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFailed to open map file.\n");
		return (NULL);
	}
	map = malloc(sizeof(char *) * 1024);
	if (!map)
	{
		ft_printf("Error\nMemmory allocation failed.\n");
		return (NULL);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i++] = line;
		free (line);
		line = NULL;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

static int	is_rectangular(char **map)
{
	size_t	len;
	int	i;

	if (!map || !map[0])
	{
		ft_printf("Error\nMap is empty or invalid.\n");
		return (0);
	}
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			ft_printf("Error\nMap is not rectangular.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	is_surrounded_by_walls(char **map)
{
	int	i;
	int	last_row;

	if (!map || !map[0])
	{
		ft_printf("Error\nInvalid map.\n");
		return (0);
	}
	last_row = 0;
	while (map[last_row])
		last_row++;
	last_row--;
	i = 0;
	while (map[0][i] && map[last_row][i])
	{
		if (map[0][i] != '1' || map[last_row][i] != '1')
		{
			ft_printf("Error\nTop or bottom row not enclosed by walls.\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
		{
			ft_printf("Error\nLeft or right not enclosed by walls.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	validate_map_components(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	player;
	int	collectible;

	exit = 0;
	player = 0;
	collectible = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			if (map[i][j] == 'P')
				player++;
			if (map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (exit != 1 || player != 1 || collectible == 0)
		ft_printf("Error\nInvalid components\n");
	return (exit == 1 && player == 1 && collectible > 0);
}

int	validate_map(char **map)
{
	if (!is_rectangular(map))
		return (0);
	if (!is_surrounded_by_walls(map))
		return (0);
	if (!validate_map_components(map))
		return (0);
	return (1);
}

int	main(void)
{
	char **map;

	map = parse_map("map1.ber");
	ft_printf("%d", validate_map(map));
}	
