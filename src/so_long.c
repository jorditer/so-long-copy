/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordi <jordi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:35:06 by antandre          #+#    #+#             */
/*   Updated: 2025/02/14 22:42:17 by jordi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game_instance;

	check_args(argc, argv);
	game_instance.fd = open(argv[1], O_RDONLY);
	if (game_instance.fd < 0 || game_instance.fd == 0)
		ft_error("Failed to open file");
	init_value(&game_instance);
	map_parser(&game_instance);
	if (map_checker(&game_instance) == 0)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, true);
		game_instance.mlx = mlx_init(IMG_W * game_instance.map.columns, \
				IMG_H * game_instance.map.rows, "so_long", true);
		if (!game_instance.mlx)
		{
			ft_error_clean("Fail initializing MLX", &game_instance);
			return (1);
		}
		init_graphics(&game_instance);
		mlx_key_hook(game_instance.mlx, &my_key_hook, &game_instance.mlx);
		mlx_loop(game_instance.mlx);
	}
	clean_up(&game_instance);
	return (0);
}
