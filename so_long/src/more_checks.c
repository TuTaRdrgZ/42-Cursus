/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:44:01 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/16 20:03:23 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_filetype(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (!(str[i + 1] == 'b') && str[i + 2] == 'e' \
					&& str[i + 3] == 'r' && !str[i + 4])
			{
				ft_putendl_fd("ERROR! Program only accepts .ber files!!", 2);
				return (-1);
			}
			else
				return (0);
		}
		i++;
	}
	return (0);
}

int	check_repeated(t_game *game, int i, int j)
{
	int	p_counter;
	int e_counter;

	p_counter = 0;
	e_counter = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				p_counter++;
			if (game->map[i][j] == 'E')
			{
				game->exit_x = i;
				game->exit_y = j;
				e_counter++;
			}
			j++;
		}
		i++;
	}
	if (p_counter != 1 || e_counter != 1)
		return (-1);
	return (0);
}
