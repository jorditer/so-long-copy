/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:40:23 by antandre          #+#    #+#             */
/*   Updated: 2024/10/08 18:31:56 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_textures(t_game *game)
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
	if (game->txt->pnj[0])
		mlx_delete_texture(game->txt->pnj[0]);
	if (game->txt->pnj[1])
		mlx_delete_texture(game->txt->pnj[1]);
	if (game->txt->pnj[2])
		mlx_delete_texture(game->txt->pnj[2]);
	if (game->txt->pnj[3])
		mlx_delete_texture(game->txt->pnj[3]);
	if (game->txt->collect)
		mlx_delete_texture(game->txt->collect);
	free(game->txt);
}

void	delete_images(t_game *game)
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
	if (game->img->pnj[0])
		mlx_delete_image(game->mlx, game->img->pnj[0]);
	if (game->img->pnj[1])
		mlx_delete_image(game->mlx, game->img->pnj[1]);
	if (game->img->pnj[2])
		mlx_delete_image(game->mlx, game->img->pnj[2]);
	if (game->img->pnj[3])
		mlx_delete_image(game->mlx, game->img->pnj[3]);
	if (game->img->collect)
		mlx_delete_image(game->mlx, game->img->collect);
	free(game->img);
}
