/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:44:50 by antandre          #+#    #+#             */
/*   Updated: 2024/10/03 17:59:25 by antandre         ###   ########.fr       */
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

void	malloc_graphics(t_game *game)
{
	game->img.wall = malloc(sizeof(mlx_image_t));
	game->img.floor[0] = malloc(sizeof(mlx_image_t));
	game->img.floor[1] = malloc(sizeof(mlx_image_t));
	game->img.player.image[0] = malloc(sizeof(mlx_image_t) * 4);
	game->img.exit.image[0] = malloc(sizeof(mlx_image_t) * 2);
	//LEAKS!!!!!!!!!!!!!!!
}

int	init_graphics(t_game *game)
{
	// Start mlx
	game->mlx = mlx_init(1000, 1000, "Test", true);
	if (!game->mlx)
        error();

	// TEXTURAS
	mlx_texture_t* p_up = mlx_load_png("assets/p_up.png");
	mlx_texture_t* p_r = mlx_load_png("assets/p_r.png");
	mlx_texture_t* p_down = mlx_load_png("assets/p_down.png");
	mlx_texture_t* p_l = mlx_load_png("assets/p_l.png");
	mlx_texture_t* wall = mlx_load_png("assets/wall.png");
	mlx_texture_t* floor1 = mlx_load_png("assets/floor1.png");
	mlx_texture_t* floor2 = mlx_load_png("assets/floor2.png");
	mlx_texture_t* collect = mlx_load_png("assets/collect.png");
	mlx_texture_t* exit1 = mlx_load_png("assets/exit1.png");
	mlx_texture_t* exit2 = mlx_load_png("assets/exit2.png");
	if(!p_up || !p_r || !p_down || !p_l || !wall || !floor1 || !floor2 ||
		!collect || !exit1 || !exit2)
		error();

	//mlx_texture_t* texture = mlx_load_png("assets/character/player.png");
	//if (!texture)
       // error();
	
	//MALLOC HORRIBLE IMAGENES
	game->img.wall = malloc(sizeof(mlx_image_t));
	game->img.floor[0] = malloc(sizeof(mlx_image_t));
	game->img.floor[1] = malloc(sizeof(mlx_image_t));
	game->img.player.image[0] = malloc(sizeof(mlx_image_t) * 4);
	game->img.exit.image[0] = malloc(sizeof(mlx_image_t) * 2);
	//LEAKS!!!!!!!!!!!!!!!
	
	// IMAGENES
	game->img.player.image[0] =  mlx_texture_to_image(game->mlx, p_up);
	game->img.player.image[1] =  mlx_texture_to_image(game->mlx, p_r);
	game->img.player.image[2] =  mlx_texture_to_image(game->mlx, p_down);
	game->img.player.image[3] =  mlx_texture_to_image(game->mlx, p_l);
	game->img.exit.image[1] =  mlx_texture_to_image(game->mlx, exit1);
	game->img.exit.image[2] =  mlx_texture_to_image(game->mlx, exit2);
	//img->collect.image[1] =  mlx_texture_to_image(game->mlx, collect);
	game->img.floor[0] =  mlx_texture_to_image(game->mlx, floor1);
	game->img.floor[1] =  mlx_texture_to_image(game->mlx, floor2);
	game->img.wall =  mlx_texture_to_image(game->mlx, wall);
	//if (!errno) // Comprobar si guarda el ultimo o cualquier error, rollo que falle el 5 y el 6 no
		//error();

	if (!game->img.player.image[0] || !game->img.player.image[1] || !game->img.player.image[2] ||
		!game->img.player.image[3] || !game->img.exit.image[0] || !game->img.exit.image[1] ||
    	!game->img.floor[0] || !game->img.floor[1] || !game->img.wall)
    	error();

	//mlx_image_t* img = mlx_texture_to_image(game->mlx, texture);
	//if (!img)
       //error();

	// Display the image
	if (mlx_image_to_window(game->mlx, game->img.wall, 0, 0) < 0)
        error();

	mlx_loop(game->mlx);

	mlx_delete_image(game->mlx, game->img.wall);
	//mlx_delete_texture(texture);

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
