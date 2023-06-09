/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:06:38 by melhadou          #+#    #+#             */
/*   Updated: 2023/01/29 16:53:21 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long nb, int *size)
{
	if (nb < 0)
	{
		ft_putchar('-', size);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10, size);
	ft_putchar(nb % 10 + '0', size);
	return ;
}
