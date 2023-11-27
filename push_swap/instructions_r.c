/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:13:07 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/27 14:17:35 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	ft_putendl_fd("ra", 1);
	return ;
}

void	rb(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	ft_putendl_fd("rd", 1);
	return ;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_putendl_fd("rr", 1);
}
