/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:44:50 by antandre          #+#    #+#             */
/*   Updated: 2024/10/02 16:08:35 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Inicializar todas las texturas e imagenes
// Guardarlas en t_img (ajustar player y exit para tener varias imagenes)
// Trasladar coordenadas de cada elemento para renderizado mapa
// Definir tamano maximo de mapa e imagenes 
// Paredes deben tener tambien suelo en un z anterior

int	init_graphics(t_game *game)
{
	// Start mlx
	game->mlx = mlx_init(1000, 1000, "Test", true);
	if (!game->mlx)
        error();

	// Load the file
	mlx_texture_t* texture = mlx_load_png("assets/character/player.png");
	if (!texture)
        error();
	
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
        error();

	// Display the image
	if (mlx_image_to_window(game->mlx, img, 0, 0) < 0)
        error();

	mlx_loop(game->mlx);

	mlx_delete_image(game->mlx, img);
	mlx_delete_texture(texture);

    // Optional, terminate will clean up any leftover images (not textures!)
	
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
