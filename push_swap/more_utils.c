/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:13:00 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/01 13:58:24 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack_a;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack_a);
	head = *stack_b;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack_b);
}

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	distance_to_min(t_list **stack, int index)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}
