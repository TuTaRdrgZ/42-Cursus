/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:24:19 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/04 16:35:12 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"

void	setup_pipes(int pipe_fd[]);
void	file_to_pipe(int pipe_fd[], char *file);
void	pipe_to_file(int pipe_fd[], char *file);
void	execute_command(char *cmd, char *const args[]);
#endif
