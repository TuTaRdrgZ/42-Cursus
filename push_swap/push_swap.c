/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:01:39 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/01 13:56:42 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_list(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 1;
	args = argv;
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		if (!new)
			return ;
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		short_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, 0);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	
	if (!argv[1] || ft_check_args(argc, argv) == -1 || (ft_isnum(argv[1]) && !argv[2]))
		return (-1);
	if (!argv[1][0] || argc < 2 || (argv[1][0] == '-' && !argv[2]))
		return (ft_error("Error"), -1);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	if (!stack_a || !stack_b)
		return (-1);
	*stack_a = NULL;
	*stack_b = NULL;
	init_list(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stacks(stack_a, stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
