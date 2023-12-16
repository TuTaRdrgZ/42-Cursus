/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:35:40 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/16 17:41:08 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	more_checks(t_game *game, char *map)
{
	if (!check_filetype(map))
		return (-1);
	if (!check_repeated(game->map, 0, 0))
		return (-1);
	return (0);
}

int	check_map(t_game *game, char *map)
{
	int	lines;
	int	col;

	lines = 0;
	while (game->map[lines])
		lines++;
	col = 0;
	while (game->map[0][col])
		col++;
	game->map_col = col;
	game->map_rows = lines;
	if (!more_checks(game, map))
	{
		free_map(game);
		return (-1); 
	}
	return (0);
}
