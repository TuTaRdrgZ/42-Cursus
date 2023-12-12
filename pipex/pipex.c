/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:22:50 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/12 10:08:52 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_pipes(t_pipe *pipex)
{
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
}

static void	child_process(t_pipe pipex, char **argv, char **envp)
{
	dup2(pipex.pipe_fd[1], 1);
	close(pipex.pipe_fd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		error_fd("Command not found", 2);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

static void	parent_process(t_pipe pipex, char **argv, char **envp)
{
	dup2(pipex.pipe_fd[0], 0);
	close(pipex.pipe_fd[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		error_fd("Command not found", 2);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;

	if (argc != 5)
		return (error_fd("Usage: infile cmd1 cmd2 outfile", 2));
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!pipex.infile || !pipex.outfile)
		exit(EXIT_FAILURE);
	if (pipe(pipex.pipe_fd) == -1)
		exit(EXIT_FAILURE);
	pipex.paths = path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid = fork();
	if (pipex.pid == -1)
		exit(EXIT_FAILURE);
	if (pipex.pid == 0)
		child_process(pipex, argv, envp);
	parent_process(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid, NULL, 0);
	parent_free(&pipex);
	return (0);
}
