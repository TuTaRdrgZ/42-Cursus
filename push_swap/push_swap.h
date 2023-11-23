/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:51:40 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/23 15:35:11 by bautrodr         ###   ########.fr       */
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
}					t_stack;

int		ft_isnum(char *str);
int		is_sorted(t_stack **stack);
int		ft_lstsize(t_stack *head);
int		push(t_stack **stack_to, t_stack **stack_from);
int		swap(t_stack **stack);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		pp(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_b, t_stack **stack_a);
int		pa(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	ft_error(char *msg);
void	ft_free(char **str);
void	free_stack(t_stack **stack);
void	ft_check_args(int argc, char **argv);
void	ft_free_stack(t_stack *stack);
void	ft_add_back(t_stack **stack, int nb);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_lstlast(t_stack *head);
t_stack	*ft_lstnew(int value);

#endif
