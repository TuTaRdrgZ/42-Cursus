/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:49:24 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/27 20:40:57 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (i);
}

int	already_exist(char **argv)
{
	int	i;
	int	num;
	int	j;

	j = 0;
	i = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			if (num == ft_atoi(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atol(args[i]);
		if (!ft_isnum(args[i]))
			return (ft_error("Error"), -1);
		if (already_exist(args))
			return (ft_error("Error"), -1);
		if (tmp < -2147483648 || tmp > 2147483647)
			return (ft_error("Error"), -1);
		i++;
	}
	if (argc == 2)
		ft_free(args);
	return (0);
}
