/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:35:06 by antandre          #+#    #+#             */
/*   Updated: 2024/10/22 19:40:52 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc, argv);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd < 0 || game.fd == 0)
		ft_error("Failed to open file");
	init_value(&game);
	map_parser(&game);
	if (map_checker(&game) == 0)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, true);
		game.mlx = mlx_init(IMG_W * game.map.columns, \
				IMG_H * game.map.rows, "so_long", true);
		if (!game.mlx)
		{
			ft_error_clean("Fail initializing MLX", &game);
			return (1);
		}
		init_graphics(&game);
		mlx_key_hook(game.mlx, &my_key_hook, &game.mlx);
		mlx_loop(game.mlx);
	}
	clean_up(&game);
	return (0);
}
