/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:22:50 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/04 16:35:09 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, int *pipe_fd)
{
	char	*cmd_args[] = {argv[2], NULL};

	file_to_pipe(pipe_fd, argv[1]);
	execute_command(argv[2], cmd_args);
}

void	parent_process(char **argv, int *pipe_fd)
{
	char	*cmd_args[] = {argv[3], NULL};

	pipe_to_file(pipe_fd, argv[4]);
	execute_command(argv[3], cmd_args);
	wait(NULL);
}

int	main(int argc, char *argv[])
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putendl_fd("Usage: infile cmd1 cmd2 outfile", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	if ((pid = fork()) == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close(pipe_fd[0]);
		child_process(argv, pipe_fd);
	}
	else
	{
		close(pipe_fd[1]);
		parent_process(argv, pipe_fd);
	}
	return (0);
}
