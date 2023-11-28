/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:49:24 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/28 14:28:38 by bautrodr         ###   ########.fr       */
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

static int	size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static int	already_exist(char **argv)
{
	int	i;
	int	num;
	int	j;
	int	len;

	len = size_tab(argv);
	i = 1;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		j = i + 1;
		while (j < len)
		{
			if (num == ft_atoi(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i = 1;
	while (str[i])
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 1;
	args = argv;
	while (args[i])
	{
		tmp = ft_atol(args[i]);
		if (is_valid_number(args[i]) == -1)
			return ((ft_error("Error")), -1);
		if (ft_isnum(args[i]) == -1)
			return (ft_error("Error"), -1);
		if (already_exist(argv) == -1)
			return (ft_error("Error"), -1);
		if (tmp < -2147483648 || tmp > 2147483647)
			return (ft_error("Error"), -1);
		i++;
	}
	return (0);
}
