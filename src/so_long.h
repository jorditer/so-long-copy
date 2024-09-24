/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:32:25 by antandre          #+#    #+#             */
/*   Updated: 2024/09/24 22:02:00 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/Libft/include/libft.h"

typedef struct s_game
{
    mlx_t   *mlx;
    mlx_image_t *player_img;
    char    **map;
    int     player_x;
    int     player_y;
    int     moves;
    int     collectibles;
} t_game;

#endif
