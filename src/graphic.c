/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:44:50 by antandre          #+#    #+#             */
/*   Updated: 2024/10/08 14:22:57 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int init_textures(t_game *game)
{
	game->texture = ft_calloc(1, sizeof(t_texture));
	if(!game->texture)
		return (1); //ft_error?
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
 	if (!game->texture->floor[0] || !game->texture->floor[1] || !game->texture->wall ||
        !game->texture->exit[0] || !game->texture->exit[1] || !game->texture->player[0] ||
				!game->texture->player[1] || !game->texture->player[2] || !game->texture->player[3] || !game->texture->collect)
    {
				delete_textures(game);
        ft_error("Failed to load some textures"); //mlx_error?
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
	if (!game->img->floor[0] || !game->img->floor[1] || !game->img->wall ||
        !game->img->exit[0] || !game->img->exit[1] || !game->img->player[0] ||
				!game->img->player[1] || !game->img->player[2] || !game->img->player[3] ||
        !game->img->collect)
    {
        delete_textures(game);
				delete_images(game);
				ft_error("Failed to create some images from textures"); //mlx_error?
    }
	delete_textures(game);
	return (0);
}

// Trasladar coordenadas de cada elemento para renderizado mapa
// Definir tamano maximo de mapa e imagenes 
// Paredes deben tener tambien suelo en un z anterior

void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.array[y])
	{
		x = 0;
		while (game->map.array[y][x])
		{
			mlx_image_to_window(game->mlx, game->img->floor[0], x * IMG_WIDTH, y * IMG_HEIGHT);
			if (game->map.array[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img->wall, x * IMG_WIDTH, y * IMG_HEIGHT);
			if (game->map.array[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img->exit[0], x * IMG_WIDTH, y * IMG_HEIGHT);
			x++;
		}
		y++;
	}
}

int	init_graphics(t_game *game)
{
	// Start mlx
	// mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(IMG_WIDTH * game->map.rows, \
			IMG_HEIGHT * game->map.columns, "so_long", true);
	if (!game->mlx)
		my_mlx_error(); //Usar mlx o mis propios errores?

	init_textures(game);
	init_images(game);

	// Display the image
	//if (mlx_image_to_window(game->mlx, game->img->player[3], 50,50) < 0)
		//my_mlx_error();
	draw_floor(game);
	mlx_loop(game->mlx);
	
	delete_images(game);

  // Optional, terminate will clean up any leftover images (not textures!)
	// FUNCION LIMPIAR TEXTURAS, LIBERAR IMAGENES!
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
