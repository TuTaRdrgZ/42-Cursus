/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:03:01 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/17 19:51:48 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	//printf("%d ", keycode);
	if (keycode == 65307)
		destroy_program(game);
	if (keycode == 119 || keycode == 65362) // w 
		update_player_pos(game, keycode);
	if (keycode == 115 || keycode == 65364) // s 
		update_player_pos(game, keycode);
	if (keycode == 97 || keycode == 65361) // a 
		update_player_pos(game, keycode);
	if (keycode == 100 || keycode == 65363) // d 
		update_player_pos(game, keycode);
	return (0);
}
