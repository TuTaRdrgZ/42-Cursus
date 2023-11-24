/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:58:17 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/24 13:02:28 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		i;

	i = 0;
	if (!(stack) || !(*stack)->next)
		return ;
	head = *stack;
	while (head->next)
	{
		head->index = i++;
		head = head->next;
	}
}
