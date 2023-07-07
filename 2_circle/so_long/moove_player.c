/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:15:46 by theophilebr       #+#    #+#             */
/*   Updated: 2022/04/26 12:58:53 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"

int	moove_check(t_game *game, int x, int y)
{
	static int	save_exit = 0;
	static int	move_cnt = 0;

	if (save_exit)
	{
		game->map[game->y_pos][game->x_pos] = 'E';
		save_exit = 0;
	}
	if (game->map[game->y_pos + y][game->x_pos + x] == '1')
		return (0);
	if (game->map[game->y_pos + y][game->x_pos + x] == 'C')
		game->obj -= 1;
	if (game->map[game->y_pos + y][game->x_pos + x] == 'E')
		save_exit++;
	if (game->map[game->y_pos + y][game->x_pos + x] == 'E' && game->obj == 0)
		end_game(game);
	move_cnt++;
	ft_printf("move count : %d\n", move_cnt);
	return (1);
}

void	moove_player(int keycode, t_game *game)
{
	if (keycode == 0 && moove_check(game, -1, 0))
	{
		game->x_pos += -1;
		game->map[game->y_pos][game->x_pos] = 'P';
		load_map(game);
	}
	if (keycode == 1 && moove_check(game, 0, 1))
	{
		game->y_pos += 1;
		game->map[game->y_pos][game->x_pos] = 'P';
		load_map(game);
	}
	if (keycode == 2 && moove_check(game, 1, 0))
	{
		game->x_pos += 1;
		game->map[game->y_pos][game->x_pos] = 'P';
		load_map(game);
	}
	if (keycode == 13 && moove_check(game, 0, -1))
	{
		game->y_pos += -1;
		game->map[game->y_pos][game->x_pos] = 'P';
		load_map(game);
	}
}
