/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constantes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:53:03 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/26 13:29:59 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTES_H
# define CONSTANTES_H
# include <stdio.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"
# define BLK_SZ 32

typedef struct s_game {
	void	*mlx;
	void	*win;
	char	**map;
	void	*spr_bl;
	void	*r_down;
	void	*r_up;
	void	*r_right;
	void	*r_left;
	void	*r_crnt;
	void	*wall;
	void	*exit;
	void	*ground;
	int		width;
	int		heigth;
	int		blk_wd;
	int		blk_hg;
	int		x_pos;
	int		y_pos;
	int		obj;
	int		x_exit;
	int		y_exit;
}				t_game;
char	**map_load(char **argv, t_game *game);
int		nbr_lign(char **argv, t_game *game);
int		map_validity_check(char **tmp, int heigth, t_game *game);
int		map_validity_parsing(char *s, int i, int width, int heigth);
int		symbol_check(char *tmp, int *c, int *e, int *p);
void	start_game(t_game *game);
void	load_map(t_game *game);
void	load_sprites(t_game *game);
void	put_to_window(t_game *game, int i, int j, void *img);
void	current_position(t_game *game, int i, int j);
int		change_position(int keycode, t_game *game);
void	moove_player(int keycode, t_game *game);
int		moove_check(t_game *game, int x, int y);
int		end_game(t_game *game);
#endif