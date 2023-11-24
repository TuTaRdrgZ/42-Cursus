/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:29:28 by bautrodr          #+#    #+#             */
/*   Updated: 2023/11/24 16:14:33 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_error("Error occured while swapping!");
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

static void sort_two_nodes(t_list **stack_a)
{
    if (!*stack_a || !(*stack_a)->next)
        return; // No hay suficientes elementos para ordenar
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}

static void sort_three_nodes(t_list **stack_a)
{
    if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
        return; // No hay suficientes elementos para ordenar

    int a = (*stack_a)->value;
    int b = (*stack_a)->next->value;
    int c = (*stack_a)->next->next->value;

    if (a > b && a > c)
        rra(stack_a);
    else if (a > b)
        sa(stack_a);
    else if (b > c)
        sb(stack_a);
}

void sort_four_nodes(t_list **stack_a, t_list **stack_b)
{
    if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next || !(*stack_a)->next->next->next)
        return; // No hay suficientes elementos para ordenar

    pb(stack_b, stack_a); // Mover el menor elemento a stack_b
    sort_three_nodes(stack_a); // Ordenar los tres elementos restantes en stack_a
    pa(stack_a, stack_b); // Mover el elemento menor de stack_b a stack_a
    sa(stack_a); // Ajustar el orden de los dos elementos superiores en stack_a

}

static void sort_five_nodes(t_list **stack_a, t_list **stack_b)
{
    if (!*stack_a && ft_lstsize(*stack_a) == 5)
        return; // No hay suficientes elementos para ordenar

    pb(stack_b, stack_a); // Mover el menor elemento a stack_b
    sort_four_nodes(stack_a, stack_b); // Ordenar los cuatro elementos restantes en stack_a
    pa(stack_a, stack_b); // Mover el elemento menor de stack_b a stack_a
	sa(stack_a);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_two_nodes(stack_a);
	else if (size == 3)
		sort_three_nodes(stack_a);
	else if (size == 4)
		sort_four_nodes(stack_a, stack_b);
	else if (size == 5)
		sort_five_nodes(stack_a, stack_b);
}
