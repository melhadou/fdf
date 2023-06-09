/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:06:32 by melhadou          #+#    #+#             */
/*   Updated: 2022/12/19 12:34:22 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long nb, int state, int *size)
{
	char	*base;

	if (state == 'x')
		base = "0123456789abcdef";
	else if (state == 'X')
		base = "0123456789ABCDEF";
	if (nb > 15)
	{
		ft_puthex(nb / 16, state, size);
		ft_putchar(base[nb % 16], size);
	}
	else
		ft_putchar(base[nb % 16], size);
	return ;
}
