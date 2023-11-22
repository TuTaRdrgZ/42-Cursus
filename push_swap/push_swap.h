/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:51:40 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/22 18:53:28 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		ft_isnum(char *str);
int		is_sorted(t_stack **stack);
void	ft_error(char *msg);
void	ft_free(char **str);
void	free_stack(t_stack **stack);
void	ft_check_args(int argc, char **argv);
void	ft_free_stack(t_stack *stack);
void	ft_add_back(t_stack **stack, int nb);

#endif
