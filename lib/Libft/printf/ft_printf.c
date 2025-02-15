/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrada <jterrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:15:58 by jterrada          #+#    #+#             */
/*   Updated: 2025/02/15 10:56:17 by jterrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_fork(va_list args, const char c)
{
	if (c == 'd' || c == 'i')
		return (ft_put_nbr(va_arg(args, int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, int), c));
	else if (c == 'c')
		return (ft_put_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_put_str(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_put_char('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	int			i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_printf_fork(args, format[i + 1]);
			i++;
		}
		else
			count += ft_put_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int a = 5;
// 	char s[] = "test";
// 	unsigned int b = 19;

// 	printf("%p\n%p\n%p", &a, &b, s);
// 	ft_printf("\n%p\n%p\n%p", &a, &b, s);
// }