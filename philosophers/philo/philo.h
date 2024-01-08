/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:38:05 by bautrodr          #+#    #+#             */
/*   Updated: 2024/01/08 18:00:15 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include <pthread.h>
# include <sys/wait.h>
# include <stdlib.h>

# define RST    "\033[0m"      /* Reset to default color */
# define RED	"\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */

typedef struct s_program	t_program;

typedef struct s_philo
{
	int				id;
	int				eating;
	int				meals_counter;
	int				nphilos;
	int				nbr_limit_meals;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_program		*program;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	long			last_meal;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
	pthread_mutex_t	start;
	pthread_mutex_t	print;
	t_philo			*philos;
	pthread_t		*threads;
}					t_program;

void	print_error(char *str);
int		is_digit_str(char *str);
int		ft_strlen(char *str);
long	ft_atol(const char *str);
void	check_and_init(t_program *program, char **argv, int argc);
int		exit_error(char *str, t_program *program);
#endif
