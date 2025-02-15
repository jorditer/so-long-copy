/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrada <jterrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:10:11 by jterrada          #+#    #+#             */
/*   Updated: 2024/11/24 13:00:40 by jterrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"

int	ft_put_x(unsigned long nb, char *alpha)
{
	int	count;

	count = 0;
	if (nb > 15)
	{
		count += ft_put_x(nb / 16, alpha);
		count += ft_put_x(nb % 16, alpha);
	}
	else
		count += ft_put_char(alpha[nb]);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_puthex(unsigned int nb, int type)
{
	char	*alpha;

	if (type == 'x')
		alpha = "0123456789abcdef";
	else
		alpha = "0123456789ABCDEF";
	return (ft_put_x(nb, alpha));
}

// int	ft_put_x(unsigned long n)
// {
// 	int		size;

// 	// if (n > LONG_MAX)
// 	// 	return (-1);
// 	size = 0;
// 	if (n >= 16)
// 		size += ft_put_x(n / 16);
// 	if (n % 16 < 10)
// 		size += ft_putchar(n % 16 + '0');
// 	else
// 		size += ft_putchar(n % 16 - 10 + 'a');
// 	return (size);
// }

// #include <stdio.h>
// int main(void)
// {
// 	ft_put_x(ULONG_MAX);
// 	printf("hey this throws an error \n%x\n", ULONG_MAX);
// 	// printf("normal %d\n", printf("\n%d\n", ft_put_x(92233720)));
// 	// printf("ft %d\n", ft_printf("\n%d\n", ft_put_x(92233720)));
// 	printf(" %x ", LONG_MAX);
// }