/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:40:23 by antandre          #+#    #+#             */
/*   Updated: 2024/10/22 19:46:17 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_textures(t_game *game)
{
	if (game->txt)
	{
		if (game->txt->floor[0])
			mlx_delete_texture(game->txt->floor[0]);
		if (game->txt->floor[1])
			mlx_delete_texture(game->txt->floor[1]);
		if (game->txt->wall)
			mlx_delete_texture(game->txt->wall);
		if (game->txt->exit[0])
			mlx_delete_texture(game->txt->exit[0]);
		if (game->txt->exit[1])
			mlx_delete_texture(game->txt->exit[1]);
		if (game->txt->pnj)
			mlx_delete_texture(game->txt->pnj);
		if (game->txt->collect)
			mlx_delete_texture(game->txt->collect);
		free(game->txt);
		game->txt = NULL;
	}
}

void	delete_images(t_game *game)
{
	if (game->img)
	{
		if (game->img->floor[0])
			mlx_delete_image(game->mlx, game->img->floor[0]);
		if (game->img->floor[1])
			mlx_delete_image(game->mlx, game->img->floor[1]);
		if (game->img->wall)
			mlx_delete_image(game->mlx, game->img->wall);
		if (game->img->exit[0])
			mlx_delete_image(game->mlx, game->img->exit[0]);
		if (game->img->exit[1])
			mlx_delete_image(game->mlx, game->img->exit[1]);
		if (game->img->pnj)
			mlx_delete_image(game->mlx, game->img->pnj);
		if (game->img->collect)
			mlx_delete_image(game->mlx, game->img->collect);
		free(game->img);
		game->img = NULL;
	}
}

void	clean_up(t_game *game)
{
	delete_images(game);
	delete_textures(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map.array || game->map.info)
		free_map(game);
	if (game->fd > 0)
		close(game->fd);
}
