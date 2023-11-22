/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:49:24 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/21 13:17:33 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **tab, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_isdigit(tab[i][0]))
			return (-1);
		i++;
	}
	return (i);
}
