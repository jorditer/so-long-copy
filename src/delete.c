/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrada <jterrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:40:23 by antandre          #+#    #+#             */
/*   Updated: 2025/02/15 11:25:46 by jterrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_textures(t_game *game)
{
	if (game->txt)
	{
		if (game->txt->floor)
			mlx_delete_texture(game->txt->floor);
		if (game->txt->wall)
			mlx_delete_texture(game->txt->wall);
		if (game->txt->exit1)
			mlx_delete_texture(game->txt->exit1);
		if (game->txt->exit2)
			mlx_delete_texture(game->txt->exit2);
		if (game->txt->pnj)
			mlx_delete_texture(game->txt->pnj);
		if (game->txt->collect)
			mlx_delete_texture(game->txt->collect);
		free(game->txt);
		game->txt = NULL;
	}
}

void	remove_images(t_game *game)
{
	if (game->img)
	{
		if (game->img->floor)
			mlx_delete_image(game->mlx, game->img->floor);
		if (game->img->wall)
			mlx_delete_image(game->mlx, game->img->wall);
		if (game->img->exit1)
			mlx_delete_image(game->mlx, game->img->exit1);
		if (game->img->exit2)
			mlx_delete_image(game->mlx, game->img->exit2);
		if (game->img->pnj)
			mlx_delete_image(game->mlx, game->img->pnj);
		if (game->img->collect)
			mlx_delete_image(game->mlx, game->img->collect);
		free(game->img);
		game->img = NULL;
	}
}

void    clean_up(t_game *game)
{
    if (game->mlx)
    {
        remove_images(game);
        remove_textures(game);
        mlx_terminate(game->mlx);
    }
    if (game->map.arr || game->map.map_copy)
        free_map(game);
    if (game->fd > 0)
        close(game->fd);
}
