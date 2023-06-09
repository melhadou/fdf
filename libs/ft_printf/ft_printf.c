/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:46:53 by melhadou          #+#    #+#             */
/*   Updated: 2022/12/19 12:40:35 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list pt, const char *str, int *size)
{
	if (*str == '%')
		ft_putchar('%', size);
	else if (*str == 'c')
		ft_putchar(va_arg(pt, int), size);
	else if (*str == 'd')
		ft_putnbr(va_arg(pt, int), size);
	else if (*str == 'i')
		ft_putnbr(va_arg(pt, int), size);
	else if (*str == 's')
		ft_putstr(va_arg(pt, char *), size);
	else if (*str == 'u')
		ft_putnbr(va_arg(pt, unsigned int), size);
	else if (*str == 'x')
		ft_puthex(va_arg(pt, unsigned int), 'x', size);
	else if (*str == 'X')
		ft_puthex(va_arg(pt, unsigned int), 'X', size);
	else if (*str == 'p')
	{
		ft_putstr("0x", size);
		ft_puthex(va_arg(pt, size_t), 'x', size);
	}
	else
		ft_putchar(*str, size);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;
	int		i;

	size = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			ft_check(args, str + ++i, &size);
		else
			ft_putchar(str[i], &size);
		if (str[i] != '\0')
			i++;
	}
	va_end(args);
	return (size);
}
