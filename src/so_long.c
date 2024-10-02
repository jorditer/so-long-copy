/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:35:06 by antandre          #+#    #+#             */
/*   Updated: 2024/10/02 15:55:14 by antandre         ###   ########.fr       */
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
	if (map_checker(&game) == 0)
	{
		//VAMOOOOOS
	}

	//HOOKS
	/*
	mlx_loop_hook();
	mlx_key_hook();
	mlx_loop(game.mlx);
	*/
	
	//GRAPHIC TESTS
	init_graphics(&game);	
	
	//Function to clean up everything
	free_map("", &game);
}
