/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:13:07 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/24 15:26:44 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*first_node;
	if (!((*stack_a)->next) || !stack_a)
		return ;
	first_node = *stack_a;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a) = first_node;
	*stack_a = first_node->next;
	first_node->next = NULL;
	ft_putendl_fd("ra", 1);
}

void rb(t_list **stack)
{
	t_list	*first_node;
    if (!(*stack) || !(*stack)->next)
        return; // La pila debe tener al menos dos elementos
    first_node = *stack;
    while ((*stack)->next)
        *stack = (*stack)->next;
    (*stack)->next = first_node;
    *stack = first_node->next;
    first_node->next = NULL;
	ft_putendl_fd("rd", 1);
}

void rr(t_list **stack_a, t_list **stack_b)
{
    ra(stack_a);
    rb(stack_b);
	ft_putendl_fd("rr", 1);
}
