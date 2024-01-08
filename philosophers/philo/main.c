/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:09:25 by bautrodr          #+#    #+#             */
/*   Updated: 2024/01/08 13:13:43 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_program	program;

	if (argc == 5 || argc == 6)
	{
		check_and_init(&program, argv, argc);
		//free_data(&philo);
		//clear program
	}
	else
	{
		print_error("Wrong input:\n"G"Correct input: ./philo <N-philos> <die-time>\
 <eat-time> <think-time> [<max-eat-count>]\n"RST);
	}
	return (0);
}
