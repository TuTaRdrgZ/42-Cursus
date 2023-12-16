/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:35:52 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/16 17:37:46 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map(t_game *game, int lines, char *map)
{
	int	file;
	int	i;

	i = 1;
	file = open(map, O_RDWR);
	game->map = malloc(sizeof(char *) * (lines + 1));
	game->map[0] = get_next_line(file);
	while (i < lines)
	{
		game->map[i] = get_next_line(file);
		i++;
	}
	if (!check_map(game, map))
		exit(EXIT_FAILURE);
}

int	init_map(char *map, t_game *game, int linecount)
{
	int		file;
	char	*line;

	file = open(map, O_RDWR);
	if (file == -1)
	{
		ft_putendl_fd("Error\nMap does not exist!", 2);
		return (1);
	}
	line = get_next_line(file);
	if (line == NULL)
		exit(EXIT_FAILURE);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		linecount++;
	}
	close(file);
	fill_map(game, linecount, map);
	free(line);
	return (0);
}
