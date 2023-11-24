/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:51:40 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/24 13:03:04 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_list;

int		ft_isnum(char *str);
int		is_sorted(t_list **stack);
int		ft_lstsize(t_list *head);
int		push(t_list **stack_to, t_list **stack_from);
int		swap(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pp(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);
int		pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	ft_error(char *msg);
void	ft_free(char **str);
void	index_stack(t_list **stack);
void	free_stack(t_list **stack);
void	ft_check_args(int argc, char **argv);
void	ft_free_stack(t_list *stack);
void	ft_add_back(t_list **stack, int nb);
void	ft_lstadd_back(t_list **stack, t_list *new);
void	ft_lstadd_front(t_list **stack, t_list *new);
t_list	*ft_lstlast(t_list *head);
t_list	*ft_lstnew(int value);

#endif
