/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:10:25 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/17 17:53:00 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	init_img(t_game *game)
{
	//agregar ifs por si fallan
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
			"img/wall.xpm", &game->width, &game->height);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx, \
			"img/grass.xpm", &game->width, &game->height);
	game->textures.coin = mlx_xpm_file_to_image(game->mlx, \
			"img/coin.xpm", &game->width, &game->height);
	game->textures.closed_door = mlx_xpm_file_to_image(game->mlx, \
			"img/closed_door.xpm", &game->width, &game->height);
	game->textures.opened_door = mlx_xpm_file_to_image(game->mlx, \
			"img/opened_door.xpm", &game->width, &game->height);
	game->player.player_up = mlx_xpm_file_to_image(game->mlx, \
			"img/looking_up.xpm", &game->width, &game->height);
	game->player.player_down = mlx_xpm_file_to_image(game->mlx, \
			"img/looking_down.xpm", &game->width, &game->height);
	game->player.player_left = mlx_xpm_file_to_image(game->mlx, \
			"img/looking_left.xpm", &game->width, &game->height);
	game->player.player_right = mlx_xpm_file_to_image(game->mlx, \
			"img/looking_right.xpm", &game->width, &game->height);
}
