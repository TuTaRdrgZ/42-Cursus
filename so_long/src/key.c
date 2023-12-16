/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:03:01 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/16 13:38:17 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	//printf("%d ", keycode);
	if (keycode == 65307)
		destroy_program(game);
	if (keycode == 119 || keycode == 65362) // w 
		printf("w\n"); // f move_player_up
	if (keycode == 115 || keycode == 65364) // s 
		printf("s\n"); // f move_player_down
	if (keycode == 97 || keycode == 65361) // a 
		printf("a\n"); // f move_player_left
	if (keycode == 100 || keycode == 65363) // d 
		printf("d\n"); // move_player_right
	return (0);
}
