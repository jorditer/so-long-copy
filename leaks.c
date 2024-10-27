/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:23:22 by antandre          #+#    #+#             */
/*   Updated: 2024/10/27 20:59:37 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(800, 600, "Ventana MLX42", true);
	if (!mlx)
		return (EXIT_FAILURE);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

// gcc leaks.c ./lib/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
