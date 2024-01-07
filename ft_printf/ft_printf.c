/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:51:58 by oyozcan           #+#    #+#             */
/*   Updated: 2023/07/24 18:55:07 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_format(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putudec(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthexa(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		y;

	va_start(ap, format);
	i = 0;
	y = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			y += ft_format(format[++i], ap);
		else if (format[i] != '%')
			y += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (y);
}
