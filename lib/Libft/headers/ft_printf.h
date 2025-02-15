/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrada <jterrada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:06:01 by jterrada          #+#    #+#             */
/*   Updated: 2025/02/15 10:39:50 by jterrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_put_char(char c);
int		ft_put_str(char *s);
int		ft_put_nbr(int n);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned int nb, int type);
int		ft_putpointer(void *ptr);
int		ft_put_x(unsigned long nb, char *alpha);
void	ft_str_cpy(char *dest, char *src);
int		ft_printf(char const *format, ...);

#endif