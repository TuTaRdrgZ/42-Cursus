/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:01:37 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/17 19:58:52 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_down(t_game *game, int i, int j)
{
	game->player_pos = DOWN;
	if (game->map[j + 1][i] == 'C')
		game->score++;
	else if (game->map[j + 1][i] == 'E' && game->coins == game->score)
		destroy_program(game);
	else if (game->map[j + 1][i] == 'E')
	{
		//door_locked_up_down(game, j + 1, i);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j + 1][i] = 'P';
	print_player(game, i, j + 1);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.floor, 0 + i * 32, 0 + (j * 32));
}

void	move_up(t_game *game, int i, int j)
{
	game->player_pos = UP;
	if (game->map[j - 1][i] == 'C')
		game->score += 1;
	else if (game->map[j - 1][i] == 'E' && game->coins == game->score)
		destroy_program(game);
	else if (game->map[j - 1][i] == 'E')
	{
		//door_locked_up_down(game, j - 1, i);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j - 1][i] = 'P';
	print_player(game, i, j - 1);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.floor, 0 + i * 32, 0 + (j * 32));
}

void	move_left(t_game *game, int i, int j)
{
	game->player_pos = LEFT;
	if (game->map[j][i - 1] == 'C')
		game->score += 1;
	else if (game->map[j][i - 1] == 'E' && game->coins == game->score)
		destroy_program(game);
	else if (game->map[j][i - 1] == 'E')
	{
		//door_locked_right_left(game, j, i - 1);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j][i - 1] = 'P';
	print_player(game, i - 1, j);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.floor, 0 + i * 32, 0 + (j * 32));
}

void	move_right(t_game *game, int i, int j)
{
	game->player_pos = RIGHT;
	if (game->map[j][i + 1] == 'C')
		game->score += 1;
	else if (game->map[j][i + 1] == 'E' && game->coins == game->score)
		destroy_program(game);
	else if (game->map[j][i + 1] == 'E')
	{
		//door_locked_right_left(game, j, i + 1);
		return ;
	}
	game->moves += 1;
	game->map[j][i] = '0';
	game->map[j][i + 1] = 'P';
	print_player(game, i + 1, j);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.floor, 0 + i * 32, 0 + (j * 32));
}

void	update_player_pos(t_game *game, int key)
{
	int	i;
	int	j;
	int	moves;

	moves = game->moves;
	i = game->x;
	j = game->y;
	ft_putnbr_fd(moves, 1);
	write(1, "\n", 1);
	if (key == 115 && game->map[j + 1][i] != '1')
		move_down(game, i, j);
	else if (key == 119 && game->map[j - 1][i] != '1')
		move_up(game, i, j);
	else if (key == 97 && game->map[j][i - 1] != '1')
		move_left(game, i, j);
	else if (key == 100 && game->map[j][i + 1] != '1')
		move_right(game, i, j);
}

void	print_player(t_game *game, int width, int height)
{
	if (game->player_pos == RIGHT)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_right, 0 + width * 32, 0 + (height * 32));
	else if (game->player_pos == LEFT)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_left, 0 + width * 32, 0 + (height * 32));
	else if (game->player_pos == UP)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_up, 0 + width * 32, 0 + (height * 32));
	else if (game->player_pos == DOWN)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_down, 0 + width * 32, 0 + (height * 32));
	game->x = width;
	game->y = height;
}