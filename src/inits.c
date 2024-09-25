/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:19:59 by antandre          #+#    #+#             */
/*   Updated: 2024/09/25 13:21:49 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_value(t_game *game)
{
	game->position.x = 0;
	game->position.y = 0;
	game->position.move = 0;
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.collectible = 0;
	game->map.exit = 0;
	game->map.player = 0;
	game->map.walls = 0;
	game->map.floor = 0;
	game->map.info = NULL;
	game->count = 0;
	game->finish_game = 0;
	game->map.calloc = NULL;
}
