/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrada <jterrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:33:09 by jterrada          #+#    #+#             */
/*   Updated: 2025/02/15 11:03:12 by jterrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(char *s)
{
	int	size;

	size = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
	{
		size += write(1, s, 1);
		s++;
	}
	if (size < 0)
		return (-1);
	return (size);
}
