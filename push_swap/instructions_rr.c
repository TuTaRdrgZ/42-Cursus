/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:22:41 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/24 15:30:49 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_list **stack_a)
{
    if (!((*stack_a)->next) || !stack_a)
        return; // La pila debe tener al menos dos elementos

    t_list *last_node = *stack_a;
    t_list *second_last_node = NULL;
    while (last_node->next)
    {
        second_last_node = last_node;
        last_node = last_node->next;
    }
    second_last_node->next = NULL;
    last_node->next = *stack_a;
    *stack_a = last_node;
    ft_putendl_fd("rra", 1);
}

void rrb(t_list **stack_b)
{
    if (!(*stack_b) || !(*stack_b)->next)
        return; // La pila debe tener al menos dos elementos

    t_list *last_node = *stack_b;
    t_list *second_last_node = NULL;
    while (last_node->next)
    {
        second_last_node = last_node;
        last_node = last_node->next;
    }
    second_last_node->next = NULL;
    last_node->next = *stack_b;
    *stack_b = last_node;
    ft_putendl_fd("rrb", 1);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    ft_putendl_fd("rrr", 1);
}
