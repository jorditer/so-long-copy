/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordi <jordi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:40:23 by antandre          #+#    #+#             */
/*   Updated: 2025/02/14 23:17:07 by jordi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_textures(t_game *game_instance)
{
	if (game_instance->txt)
	{
		if (game_instance->txt->floor)
			mlx_delete_texture(game_instance->txt->floor);
		if (game_instance->txt->wall)
			mlx_delete_texture(game_instance->txt->wall);
		if (game_instance->txt->exit1)
			mlx_delete_texture(game_instance->txt->exit1);
		if (game_instance->txt->exit2)
			mlx_delete_texture(game_instance->txt->exit2);
		if (game_instance->txt->pnj)
			mlx_delete_texture(game_instance->txt->pnj);
		if (game_instance->txt->collect)
			mlx_delete_texture(game_instance->txt->collect);
		free(game_instance->txt);
		game_instance->txt = NULL;
	}
}

void	remove_images(t_game *game_instance)
{
	if (game_instance->img)
	{
		if (game_instance->img->floor)
			mlx_delete_image(game_instance->mlx, game_instance->img->floor);
		if (game_instance->img->wall)
			mlx_delete_image(game_instance->mlx, game_instance->img->wall);
		if (game_instance->img->exit1)
			mlx_delete_image(game_instance->mlx, game_instance->img->exit1);
		if (game_instance->img->exit2)
			mlx_delete_image(game_instance->mlx, game_instance->img->exit2);
		if (game_instance->img->pnj)
			mlx_delete_image(game_instance->mlx, game_instance->img->pnj);
		if (game_instance->img->collect)
			mlx_delete_image(game_instance->mlx, game_instance->img->collect);
		free(game_instance->img);
		game_instance->img = NULL;
	}
}

void	clean_up(t_game *game_instance)
{
	remove_images(game_instance);
	remove_textures(game_instance);
	if (game_instance->mlx)
		mlx_terminate(game_instance->mlx);
	if (game_instance->map.array || game_instance->map.info)
		free_map(game_instance);
	if (game_instance->fd > 0)
		close(game_instance->fd);
}
