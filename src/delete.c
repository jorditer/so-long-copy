/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:40:23 by antandre          #+#    #+#             */
/*   Updated: 2024/10/08 12:49:40 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  delete_textures(t_game *game)
{
	if (game->texture->floor[0])
		mlx_delete_texture(game->texture->floor[0]);
	if (game->texture->floor[1])
		mlx_delete_texture(game->texture->floor[1]);
	if (game->texture->wall)
		mlx_delete_texture(game->texture->wall);
	if (game->texture->exit[0])
		mlx_delete_texture(game->texture->exit[0]);
	if (game->texture->exit[1])
		mlx_delete_texture(game->texture->exit[1]);
	if (game->texture->player[0])
		mlx_delete_texture(game->texture->player[0]);
	if (game->texture->player[1])
		mlx_delete_texture(game->texture->player[1]);
	if (game->texture->player[2])
		mlx_delete_texture(game->texture->player[2]);
	if (game->texture->player[3])
		mlx_delete_texture(game->texture->player[3]);
	if (game->texture->collect)
		mlx_delete_texture(game->texture->collect);
	free(game->texture);
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
	if (game->img->player[0])
		mlx_delete_image(game->mlx, game->img->player[0]);
	if (game->img->player[1])
		mlx_delete_image(game->mlx, game->img->player[1]);
	if (game->img->player[2])
		mlx_delete_image(game->mlx, game->img->player[2]);
	if (game->img->player[3])
		mlx_delete_image(game->mlx, game->img->player[3]);
	if (game->img->collect)
		mlx_delete_image(game->mlx, game->img->collect);
	free(game->img);
}
