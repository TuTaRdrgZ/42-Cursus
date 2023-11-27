/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:00:41 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/27 13:37:09 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(t_list **stack, int prev_min)
{
	t_list	*head;
	int		min;

	if (!stack)
		return (-1);
	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if (head->index < min && head->index != prev_min)
			min = head->index;
	}
	return (min);
}

void	short_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_two_nodes(stack_a);
	else if (size == 3)
		sort_three_nodes(stack_a, stack_b);
	else if (size == 4)
		sort_four_nodes(stack_a, stack_b);
	else if (size == 5)
		sort_five_nodes(stack_a, stack_b);
}
