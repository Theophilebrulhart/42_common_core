/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:03:56 by theophilebr       #+#    #+#             */
/*   Updated: 2022/01/04 15:20:57 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"

void	current_position(t_game *game, int i, int j)
{
	game->x_pos = j;
	game->y_pos = i;
	game->map[i][j] = '0';
	put_to_window(game, i, j, game->r_crnt);
}

void	put_to_window(t_game *game, int i, int j, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, j * BLK_SZ, i * BLK_SZ);
}

void	load_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (i++ < game->blk_hg - 1)
	{
		j = -1;
		while (j++ < game->blk_wd)
		{
			if (game->map[i][j] == 'C' || game->map[i][j] == 'P'
				|| game->map[i][j] == 'E' || game->map[i][j] == '0')
				put_to_window(game, i, j, game->ground);
			if (game->map[i][j] == '1')
				put_to_window(game, i, j, game->wall);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->spr_bl,
					j * BLK_SZ, i * BLK_SZ);
			if (game->map[i][j] == 'E' && game->obj == 0)
				put_to_window(game, i, j, game->exit);
			if (game->map[i][j] == 'P')
				current_position(game, i, j);
		}
	}
}

void	load_sprites(t_game *game)
{
	game->r_up = mlx_xpm_file_to_image(game->mlx, "./sprt/crct/r_up.xpm",
			&game->width, &game->heigth);
	game->r_down = mlx_xpm_file_to_image(game->mlx, "./sprt/crct/r_down.xpm",
			&game->width, &game->heigth);
	game->r_left = mlx_xpm_file_to_image(game->mlx, "./sprt/crct/r_left.xpm",
			&game->width, &game->heigth);
	game->r_right = mlx_xpm_file_to_image(game->mlx, "./sprt/crct/r_right.xpm",
			&game->width, &game->heigth);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./sprt/wall.xpm",
			&game->width, &game->heigth);
	game->spr_bl = mlx_xpm_file_to_image(game->mlx, "./sprt/spr_bl.xpm",
			&game->width, &game->heigth);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./sprt/exit.xpm",
			&game->width, &game->heigth);
	game->ground = mlx_xpm_file_to_image(game->mlx, "./sprt/ground.xpm",
			&game->width, &game->heigth);
	game->r_crnt = game->r_down;
}

void	start_game(t_game *game)
{
	load_sprites(game);
	load_map(game);
	mlx_hook(game->win, 2, 1L << 0, change_position, game);
	mlx_hook(game->win, 17, 1L << 0, end_game, game);
}
