/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:18:08 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/16 21:07:32 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_data(t_game *game, char *argv)
{
	game->width = 800;
	game->height = 480;
	game->moves = 0;
	game->coins = 0;
	game->score = 0;
	game->player_pos = 0;
	init_img(game);
	if (init_map(argv, game, 0) == -1)
		return (-1);
	return (0);
}

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		write(1, "Numero de argumentos incorrecto.\n", 33);
		return (0);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->mlx = mlx_init();
	if (init_data(game, argv[1]) == -1)
		destroy_program(game);
	game->window = mlx_new_window(game->mlx, (game->map_col - 1) * 32, \
		(game->map_rows + 1) * 32, "so_long");
	mlx_key_hook(game->window, key_hook, game);
	add_graphics(game);
	mlx_hook(game->window, 17, 0, destroy_program, game);
	mlx_loop(game->mlx);
	destroy_program(game);
	return (0);
}
