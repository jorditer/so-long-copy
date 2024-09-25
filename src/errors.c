/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:18:58 by antandre          #+#    #+#             */
/*   Updated: 2024/09/25 12:15:39 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *msg)
{
	ft_printf("[ERROR] %s\n", msg);
	exit(1);
}

/*
void	ft_free_map(char *msg, t_game *game)
{

}*/
