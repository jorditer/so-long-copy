/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:44:50 by antandre          #+#    #+#             */
/*   Updated: 2024/10/08 12:07:52 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static int init_textures(t_game *game)
{
	game->texture = ft_calloc(1, sizeof(t_texture));
	if(!game->texture)
		return (1);
	game->texture->floor[0] = mlx_load_png("./assets/floor1.png");
	game->texture->floor[1] = mlx_load_png("./assets/floor2.png");
	game->texture->wall = mlx_load_png("./assets/wall.png");
	game->texture->exit[0] = mlx_load_png("./assets/exit1.png");
	game->texture->exit[1] = mlx_load_png("./assets/exit2.png");
	game->texture->player[0] = mlx_load_png("./assets/p_up.png");
	game->texture->player[1] = mlx_load_png("./assets/p_down.png");
	game->texture->player[2] = mlx_load_png("./assets/p_l.png");
	game->texture->player[3] = mlx_load_png("./assets/p_r.png");
	game->texture->collect = mlx_load_png("./assets/collect.png");
	//Controlar si alguna textura falla return error
 	if (!game->texture->floor[0] || !game->texture->floor[1] || !game->texture->wall ||
        !game->texture->exit[0] || !game->texture->exit[1] || !game->texture->player[0] ||
				!game->texture->player[1] || !game->texture->player[2] || !game->texture->player[3] || !game->texture->collect)
    {
				delete_textures(game);
        ft_error("Error: Failed to load some textures\n");
    }
		return (0);
}

static int	init_images(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_img));
	if (!game->img)
		ft_error("Failed allocation for images");
	game->img->floor[0] = mlx_texture_to_image(game->mlx, game->texture->floor[0]);
	game->img->floor[1] = mlx_texture_to_image(game->mlx, game->texture->floor[1]);
	game->img->wall = mlx_texture_to_image(game->mlx, game->texture->wall);
	game->img->exit[0] = mlx_texture_to_image(game->mlx, game->texture->exit[0]);
	game->img->exit[1] = mlx_texture_to_image(game->mlx, game->texture->exit[1]);
	game->img->player[0] = mlx_texture_to_image(game->mlx, game->texture->player[0]);
	game->img->player[1] = mlx_texture_to_image(game->mlx, game->texture->player[1]);
	game->img->player[2] = mlx_texture_to_image(game->mlx, game->texture->player[2]);
	game->img->player[3] = mlx_texture_to_image(game->mlx, game->texture->player[3]);
	game->img->collect = mlx_texture_to_image(game->mlx, game->texture->collect);
	// Controlar si alguna imagen falla return error
	if (!game->img->floor[0] || !game->img->floor[1] || !game->img->wall ||
        !game->img->exit[0] || !game->img->exit[1] || !game->img->player[0] ||
				!game->img->player[1] || !game->img->player[2] || !game->img->player[3] ||
        !game->img->collect)
    {
        delete_textures(game);
				//free(game->img);
				ft_error("Failed to create some images from textures\n");
    }
		return (0);
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

	init_textures(game);
	//mlx_texture_t* texture = mlx_load_png("assets/character/player.png");
	//if (!texture)
       // error();
	
	init_images(game);
	//mlx_image_t* img = mlx_texture_to_image(game->mlx, texture);
	//if (!img)
       //error();

	// Display the image
	if (mlx_image_to_window(game->mlx, game->img->wall, 50,50) < 0)
        error();

	mlx_loop(game->mlx);
	
	mlx_delete_image(game->mlx, game->img->wall);

  // Optional, terminate will clean up any leftover images (not textures!)
	// FUNCION LIMPIAR TEXTURAS, LIBERAR IMAGENES!
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
/*
int	display_graphics(t_game *game)
{
	int	i;
	int	x;
	int y;

	i = 0;
	while (map->array)
	{
	
	}
}*/
