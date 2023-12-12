/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:57:49 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/12 15:50:31 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig_bits(char ch_msg, pid_t server_pid)
{
	int	bits;

	bits = 7;
	while (bits >= 0)
	{
		if ((ch_msg >> bits & 1) == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		--bits;
		usleep(75);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc == 3)
	{
		while (argv[2][++i])
			send_sig_bits(argv[2][i], ft_atoi(argv[1]));
	}
	else
		ft_putendl_fd("Incorrect arguments,\
			   	correct use:\t./client <PID> <msg>\n", 2);
	return (0);
}
