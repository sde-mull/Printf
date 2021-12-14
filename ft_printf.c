/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:54:09 by sde-mull          #+#    #+#             */
/*   Updated: 2021/12/14 19:13:25 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_char(char *format, va_list args, t_vars *vars, int subcount)
{
	while (++index && subcount == vars->counter)
	{
		if (format[index] == 'c')
			counter += ft_putchar(va_arg(args, int), *subflag);
		else if (format[index] == 's')
			counter += ft_putstr(va_arg(args, char *), *subflag);
		else if (format[index] == 'p')
			counter += ft_put_hex_nbr(va_arg(args, unsigned int), *subflag);
		else if (format[index] == 'd' || format[index] == 'i')
			counter += ft_putnbr(va_arg(args, int), *subflag);
		else if (format[index] == 'u')
			counter += ft_putnbr(va_arg(args, unsigned int), *subflag);
		else if (format[index] == 'x')
			counter += ft_put_hex_nbr(va_arg(args, unsigned int), *subflag);
		else if (format[index] == 'X')
			counter += ft_put_hex_nbr(va_arg(args, unsigned int), *subflag);
		else if (format[index] == '%')
			counter += ft_putchar('%');
		else
			subflag[index - counter] = format[index];
	}
}

int	ft_printf(const char *format, ...)
{
	t_vars	vars;
	va_list	args;

	vars.index = 0;
	vars.counter = 0;
	va_start(args, format);
	if (format == 0)
		return (NULL);
	while (*format != '\0')
	{
		if (*format == '%')
			ft_format_char(*format, args, &vars, vars.counter);
		else
			counter += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (counter);
}
