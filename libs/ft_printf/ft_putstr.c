/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:08:38 by melhadou          #+#    #+#             */
/*   Updated: 2022/12/19 12:39:49 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *size)
{
	int	i;

	i = 0;
	if (!str)
		*size += write(1, "(null)", 6);
	else
	{
		while (str[i] != '\0')
			ft_putchar(str[i++], size);
	}
	return ;
}
