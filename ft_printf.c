/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:54:09 by sde-mull          #+#    #+#             */
/*   Updated: 2021/12/07 16:42:33 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_format_char(char *format, int index, va_list args, int counter)
{
	index++;
	if (format[index] == c)
		counter = counter + ft_putchar(va_arg(args, char));
	else if (format[index] == s)
		counter = counter + ft_putstr(va_arg(args, char *));
	else if (format[index] == p)
		counter = counter + ft_put_hex_nbr(va_arg(args, unsigned int));
	else if (format[index] == d)
		counter = counter + ft_putnbr(va_arg(args, int));
	else if (format[index] == i)
		counter = counter + ft_putnbr(va_arg(args, int));
	else if (format[index] == u)
		counter = counter + ft_putnbr(va_arg(args, unsigned int));
	else if (format[index] == x)
		counter = counter + ft_put_hex_nbr(va_arg(args, unsigned int));
	else if (format[index] == X)
		counter = counter + ft_put_hex_nbr(va_arg(args, unsigned int));
	else if (format[index] == '%')
		counter = counter + ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int		index;
	int		counter;
	va_list	args;

	index = 0;
	counter = 0;
	va_start(args, format);
	if (format == 0)
		return (NULL);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
			ft_format_char(format, index, args, counter);
		counter = counter + ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (counter);
}
