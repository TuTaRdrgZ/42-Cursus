/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:50:44 by bautrodr          #+#    #+#             */
/*   Updated: 2023/09/26 10:37:03 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	print_hex_address(unsigned long long x, int len)
{
	char	*hex;
	int		result[20];
	int		i;

	if (len == -1)
		return (-1);
	hex = "0123456789abcdef";
	i = 0;
	while (x >= 16)
	{
		result[i] = hex[x % 16];
		x = x / 16;
		i++;
	}
	result[i] = hex[x];
	while (i >= 0)
	{
		len = ft_putchar(result[i], len);
		i--;
	}
	if (len == -1)
		return (-1);
	return (len);
}

int	print_address(void *ptr, int i)
{
	if (ptr == NULL)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		i += 3;
		return (i);
	}
	i = print_str("0x", i);
	i = print_hex_address((unsigned long long)ptr, i);
	return (i);
}
