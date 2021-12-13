/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:55:19 by sde-mull          #+#    #+#             */
/*   Updated: 2021/12/13 17:57:02 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_put_hex_nbr(unsigned int numb)
{
	if (numb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (numb < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (numb >= 16)
		{
			ft_putnbr(numb / 16);
			ft_putnbr(numb % 16);
		}
		else
		{
			if (numb < 10)
				ft_putchar(numb + '0');
			else if (numb > 10 && numb < 16)
				ft_putchar(numb + )
		}
	}
}
// --------------------------------------
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
//------------------------------------------
void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
		{
			ft_putchar(n + '0');
		}
	}
}
//---------------------------------------
void	ft_putstr(char *s)
{
	int	index;

	index = 0;
	if (s == 0)
		return ;
	while (s[index] != '\0')
	{
		ft_putchar(s[index]);
		index++;
	}
}
