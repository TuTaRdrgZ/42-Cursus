/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:36:03 by bautrodr          #+#    #+#             */
/*   Updated: 2023/09/26 10:41:35 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_putnbr(int nb, int i)
{
	if (i == -1)
		return (-1);
	if (nb <= -2147483648)
	{
		i = ft_putchar('-', i);
		i = ft_putchar('2', i);
		i = ft_putnbr(147483648, i);
	}
	else if (nb < 0)
	{
		i = ft_putchar('-', i);
		i = ft_putnbr(-nb, i);
	}
	else if (nb > 9)
	{
		i = ft_putnbr(nb / 10, i);
		i = ft_putnbr(nb % 10, i);
	}
	else
		i = ft_putchar(nb + '0', i);
	return (i);
}
