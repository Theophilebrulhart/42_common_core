/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:47:01 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/26 12:50:26 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		if (argc < 2)
			ft_putstr_fd("\nerror[arguments] : MISSING MAP\n\n", 1);
		if (argc > 2)
			ft_putstr_fd("\nerror[arguments] : TOO MANY ARGUMENTS\n\n", 1);
		return (1);
	}
	game.map = map_load(argv, &game);
	if (!game.map)
	{
		ft_putstr_fd("\nerror[map] : MAP IS INVALID\n\n", 1);
		return (1);
	}
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.blk_wd * BLK_SZ,
			game.blk_hg * BLK_SZ, "SO_LONG");
	start_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
