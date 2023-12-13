/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:28:51 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/13 20:53:04 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int sig)
{
    static int bit = 0;
    static unsigned char ch = '\0';

    if (sig == SIGUSR1)
        ch |= (1 << (7 - bit));
    bit++;
    if (bit == 8)
    {
        if (ch != '\0')
            ft_putchar_fd(ch, 1);
        bit = 0;
        ch = '\0';
    }
}

static void	ft_printserver_pid(char *str, int server_pid)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	ft_putnbr_fd(server_pid, 1);
	write(1, "\n", 1);
}

void set_handlers(void)
{
    struct sigaction	sa;
	pid_t				server_pid;

	server_pid = getpid();
	if (!server_pid)
		ft_putendl_fd("No Server PID", 2);
	else
		ft_printserver_pid("Server PID--> ", server_pid);	
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_putendl_fd("sigaction failed", 2);
        exit(EXIT_FAILURE);
    }
}

int main(void)
{
    set_handlers();
    while (1)
    {
        pause();
    }
    return 0;
}
