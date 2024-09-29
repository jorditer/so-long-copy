/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:35:06 by antandre          #+#    #+#             */
/*   Updated: 2024/09/29 19:03:54 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	//check_args(argc, argv, &game);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd < 0 || game.fd == 0)
		ft_error("Failed to open file");
	//Functions to initialize values, maps, layers, mlx, textures
	init_value(&game);
	map_parser(&game);
	ft_printf("%d", map_checker(&game));
	/*
	mlx_loop_hook();
	mlx_key_hook();
	mlx_loop(game.mlx);
	*/
	//Function to clean up everything
	free_map("Maps freed", &game);
}
