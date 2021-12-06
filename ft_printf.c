/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:54:09 by sde-mull          #+#    #+#             */
/*   Updated: 2021/12/06 19:26:08 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_char(char *format, int index, va_list arg)
{

}


int	ft_printf(const char *format, ...)
{
	int		index;

	index = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
			ft_format_char(format, index, va_list arg);
		ft_putchar(format[index]);
		index++;	
	}
}
