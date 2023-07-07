/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:12:33 by theophilebr       #+#    #+#             */
/*   Updated: 2022/01/04 14:27:55 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"

int	change_position(int keycode, t_game *game)
{
	if (keycode == 53)
		end_game(game);
	if (keycode == 0)
	{
		game->r_crnt = game->r_left;
		moove_player(keycode, game);
	}
	if (keycode == 1)
	{
		game->r_crnt = game->r_down;
		moove_player(keycode, game);
	}
	if (keycode == 2)
	{
		game->r_crnt = game->r_right;
		moove_player(keycode, game);
	}
	if (keycode == 13)
	{
		game->r_crnt = game->r_up;
		moove_player(keycode, game);
	}
	return (0);
}
