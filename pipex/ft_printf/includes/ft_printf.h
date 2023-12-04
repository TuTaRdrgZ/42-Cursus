/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:24:11 by bautrodr          #+#    #+#             */
/*   Updated: 2023/09/26 10:30:29 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		ft_putchar(char c, int i);
int		ft_putnbr(int nb, int i);
int		print_str(const char *str, int i);
int		print_hex(unsigned int x, int len, int c);
int		print_address(void *ptr, int i);
int		unsigned_int(unsigned int nb, int i);
int		check_format(va_list args, const char *format, int i, int j);
char	*ft_strchr(const char *s, int c);

#endif
