/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:12:33 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/27 15:27:51 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 0)
		return (-1);
	push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_b, t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 0)
		return (-1);
	push(stack_b, stack_a);
	ft_putendl_fd("pb", 1);
	return (0);
}

int	pp(t_list **stack_a, t_list **stack_b)
{
	int	tmp_value;

	if (!(*stack_a) || !(*stack_b) || !((*stack_a)->next)
		|| !((*stack_b)->next))
		return (-1);
	tmp_value = (*stack_a)->value;
	pa(stack_a, stack_b);
	pb(stack_b, stack_a);
	(*stack_a)->value = tmp_value;
	return (0);
}
