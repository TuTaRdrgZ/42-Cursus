/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_to_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:31:19 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/30 09:49:11 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_nodes(t_list **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

static void	sort_three_more(t_list **stack_a, t_list *head, int min,
		int next_min)
{
	if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->index == min)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	sort_three_nodes(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		min;
	int		next_min;

	if (is_sorted(stack_a))
		return ;
	head = *stack_a;
	min = min_index(stack_a, -1);
	next_min = min_index(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else
		sort_three_more(stack_a, head, min, next_min);
}

void	sort_four_nodes(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = distance_to_min(stack_a, min_index(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_b, stack_a);
	sort_three_nodes(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_five_nodes(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = distance_to_min(stack_a, min_index(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_b, stack_a);
	sort_four_nodes(stack_a, stack_b);
	pa(stack_a, stack_b);
}
