/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:58:17 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/24 14:45:07 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list *get_next_min(t_list **stack)
{
    t_list *head;
    t_list *min;

	min = NULL;
	head = *stack;
    while (head)
    {
        if (head->index == -1 && (!min || head->value < min->value))
            min = head;
        head = head->next;
    }
    return min;
}

void index_stack(t_list **stack)
{
    t_list *head;
    int index;

	index = 0;
	head = *stack;
    while (head)
    {
        if (head->index == -1)
            head->index = index++;
        head = head->next;
    }
}
