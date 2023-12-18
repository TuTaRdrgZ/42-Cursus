/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:35:40 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/18 18:17:12 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	more_checks(t_game *game, char *map)
{
	if (check_filetype(map) == -1)
		return (-1);
	if (check_repeated(game, 0, 0) == -1)
	{
		ft_putendl_fd("Invalid Map!", 2);
		return (-1);
	}
	return (0);
}

int	check_map(t_game *game, char *map)
{
	int	lines;
	int	col;

	lines = 0;
	col = 0;
	while (game->map[lines])
		lines++;
	while (game->map[0][col])
		col++;
	game->map_col = col;
	game->map_rows = lines - 1;
	if (more_checks(game, map) == -1)
	{
		free_map(game);
		return (-1); 
	}
	return (0);
}
