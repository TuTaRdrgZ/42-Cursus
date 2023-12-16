/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:07:34 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/16 20:44:10 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include<unistd.h>
# include<stdlib.h>
# include<limits.h>
# include<stdio.h>
# include<fcntl.h>

typedef struct s_textures
{
	void	*floor;
	void	*coin;
	void	*closed_door;
	void	*opened_door;
	void	*wall;
}			t_textures;

typedef struct s_player
{
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
}			t_player;

typedef struct	s_game
{
	void		*window;
	void		*mlx;
	int			width;
	int			height;
	int			moves;
	int			x;
	int			y;
	int			coins;
	int			score;
	int			player_pos;
	int			map_col;
	int			map_rows;
	int			exit_x;
	int			exit_y;
	char		**map;
	t_textures	textures;
	t_player	player;
}				t_game;

int		destroy_program(t_game *game);
void	free_map(t_game *game);

//graphics
void	init_img(t_game *game);
void	add_graphics(t_game *game);
void	print_map(char *line, t_game *game, int index);
//keys
int		key_hook(int keycode, t_game *game);

// map
int		init_map(char *map, t_game *game, int linecount);
int		check_map(t_game *game, char *map);
int		more_checks(t_game *game, char *map);
int		check_filetype(char *str);
int		check_repeated(t_game *game, int i, int j);



#endif
