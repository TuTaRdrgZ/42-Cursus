/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:22:41 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/28 14:29:16 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*head;
	t_list	*tail;

	if (!((*stack_a)->next) || !stack_a)
		return ;
	head = *stack_a;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack_a;
	*stack_a = tail;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b)
{
	t_list	*head;
	t_list	*tail;

	if (!((*stack_b)->next) || !stack_b)
		return ;
	head = *stack_b;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack_b;
	*stack_b = tail;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_putendl_fd("rrr", 1);
}
