/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:49:51 by bautrodr          #+#    #+#             */
/*   Updated: 2024/01/09 12:00:32 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	more_init(t_program *program)
{
	program->philos = malloc(program->philos->nphilos * sizeof(t_philo));
	program->threads = malloc(program->philos->nphilos * sizeof(pthread_t));
	if (!program->philos || !program->threads)
		print_error("Malloc Error");
}

void	init_philos(t_program *program, char **argv)
{
	int	i;

	i = 0;
	while (i < program->philos->nphilos)
	{
		program->philos[i].id = i + 1;
		program->philos[i].eating = 0;
		program->philos[i].meals_counter = 0;
		program->philos[i].dead = 0;
		if (i != 0)
			program->philos[i].l_fork = program->philos[i -1].r_fork;
		program->philos[i].program = program;
		i++;
	}
}

void	check_and_init(t_program *program, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_digit_str(argv[i]) == -1)
			print_error("Only positive numbers are accepted\n");
		i++;
	}
	init_philos(program, argv);
	program->philos->dead = 0;
	program->philos->nphilos = ft_atol(argv[1]);
	if (program->philos->nphilos > 200)
		print_error("You should not test with more than 200 philos!!\n");
	program->time_to_die = ft_atol(argv[2]);
	program->time_to_eat = ft_atol(argv[3]);
	program->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		program->philos->nbr_limit_meals = ft_atol(argv[5]);
	else
		program->philos->nbr_limit_meals = -1;
	more_init(program);
}
