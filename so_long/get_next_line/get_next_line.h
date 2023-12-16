/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:42:24 by bautrodr          #+#    #+#             */
/*   Updated: 2023/10/12 10:36:13 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2, size_t len1, size_t len2);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*read_line(int fd, char *str);
char	*ft_get_line(char *str);
char	*ft_free(char **str);
size_t	ft_strlen(const char *str);

#endif
