/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:51:40 by oyozcan           #+#    #+#             */
/*   Updated: 2023/07/24 18:51:45 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	ft_putnbr(int nb)
{
	char	buffer[11];
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb < 0)
	{
		y += write(1, "-", 1);
		nb = -nb;
	}
	while (nb)
	{
		buffer[i++] = nb % 10 + 48;
		nb /= 10;
	}
	while (i--)
		y += write(1, &buffer[i], 1);
	return (y);
}

int	ft_putudec(unsigned int nb)
{
	static char	buffer[10];
	int			i;
	int			y;

	if (nb == 0)
		return (write(1, "0", 1));
	i = 0;
	y = 0;
	while (nb)
	{
		buffer[i++] = nb % 10 + 48;
		nb /= 10;
	}
	while (i--)
		y += write(1, &buffer[i], 1);
	return (y);
}

int	ft_puthexa(unsigned int nb, char *base)
{
	static char	buffer[8];
	int			i;
	int			y;

	if (nb == 0)
		return (write(1, "0", 1));
	i = 0;
	y = 0;
	while (nb)
	{
		buffer[i++] = base[nb % 16];
		nb /= 16;
	}
	while (i--)
		y += write(1, &buffer[i], 1);
	return (y);
}

int	ft_putptr(void *ptr)
{
	char			buffer[16];
	int				x;
	unsigned long	temp;
	int				i;

	temp = (unsigned long)ptr;
	if (!temp)
		return (write(1, "0x0", 3));
	x = 0;
	i = 0;
	while (temp)
	{
		buffer[i++] = "0123456789abcdef"[temp % 16];
		temp = temp / 16;
	}
	x += write(1, "0x", 2);
	while (i--)
		x += write(1, &buffer[i], 1);
	return (x);
}
