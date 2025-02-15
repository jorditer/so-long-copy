/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrada <jterrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:33:03 by jterrada          #+#    #+#             */
/*   Updated: 2025/02/15 10:38:09 by jterrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned int	temp;
	int				size;

	size = 0;
	if (n / 10)
	{
		size += ft_putunsigned(n / 10);
	}
	temp = (n % 10) + '0';
	write(1, &temp, 1);
	size++;
	return (size);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("\n%i\n", ft_putunsigned(1234567890));
// 	write(1, "\n", 1);
// 	ft_putunsigned(-5);
// }