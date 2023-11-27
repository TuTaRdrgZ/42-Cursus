/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:26:01 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/27 16:46:57 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **stack_a, t_list **stack_b, int j)
{
	t_list	*head;
	int		size;
	int		i;

	i = 0;
	head = *stack_a;
	size = ft_lstsize(*stack_a);
	while (!is_sorted(stack_a))
	{
		j = 0;
		while (j++ < size)
		{
			head = *stack_a;
			if ((head->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
