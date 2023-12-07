/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:24:19 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/07 14:43:15 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_pipe
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe_fd[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipe;

int		error_fd(char *str, int fd);
char	*path(char **envp);
char	*cmd(char **paths, char *cmd);
void	child_free(t_pipe *pipex);
void	parent_free(t_pipe *pipex);
#endif
