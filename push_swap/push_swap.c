/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:01:39 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/21 13:18:20 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if (argc == 2 && argv[1][1])
		argv = ft_split(argv[1]);
	else
	{
		if (check_args(argv, argc) > 0)
		{

		}
			
	}
}
