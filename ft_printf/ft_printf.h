/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyozcan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:52:17 by oyozcan           #+#    #+#             */
/*   Updated: 2023/07/24 18:52:27 by oyozcan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putudec(unsigned int nbr);
int	ft_puthexa(unsigned int nbr, char *list);
int	ft_putptr(void *ptr);
int	ft_printf(const char *format, ...);

#endif
