/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:43:25 by bautrodr          #+#    #+#             */
/*   Updated: 2024/01/08 18:00:27 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int is_digit(char c)
{
	return ((c >= '0' && c <= '9') || c == '+');
}

int	is_digit_str(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (-1);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (result > INT_MAX)
		print_error("Max value: INT_MAX\n");
	return (result * sign);
}

void	print_error(char *str)
{
	printf(RED"%s"RST, str);
	exit(EXIT_FAILURE);
}

int	exit_error(char *str, t_program *program)
{
	int	i;

	print_error(str);
	pthread_mutex_destroy(&program->start);
	pthread_mutex_destroy(&program->print);
	i = 0;
	while (i < program->philos->nphilos)
	{
		pthread_mutex_destroy(program->philos[i].r_fork);
		//free(program->philos[i].str_num);
		++i;
	}
	free(program->philos);
	free(program->threads);
	return (0);
}
