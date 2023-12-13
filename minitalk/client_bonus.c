/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:33:03 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/13 20:56:51 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static void	confirmation_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putendl_fd("Signal received", 1);
		usleep(100);
	}
	else
		printf("error");
}

void	send_sig_bits(char ch_msg, pid_t server_pid)
{
    int bits;

    bits = 7;
    while (bits >= 0)
    {
        if ((ch_msg >> bits & 1) == 1)
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);
        --bits;
        usleep(200);
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {	
		signal(SIGUSR1, confirmation_handler);
		signal(SIGUSR2, confirmation_handler);
        while (*argv[2])
            send_sig_bits(*argv[2]++, ft_atoi(argv[1]));
    }
    else
    {
        ft_putendl_fd("Incorrect arguments!!\n", 2);
        ft_putendl_fd("correct use: ./client <PID> <msg>\n", 2);
    }
    return (0);
}
