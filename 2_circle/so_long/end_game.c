/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:28:22 by theophilebr       #+#    #+#             */
/*   Updated: 2022/04/26 13:10:46 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"

void	free_all(t_game *game)
{
	mlx_destroy_image(game->mlx, game->r_down);
	mlx_destroy_image(game->mlx, game->r_up);
	mlx_destroy_image(game->mlx, game->r_left);
	mlx_destroy_image(game->mlx, game->r_right);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->ground);
	mlx_destroy_image(game->mlx, game->spr_bl);
	mlx_destroy_image(game->mlx, game->exit);
	free(game->map);
}

int	end_game(t_game *game)
{
	if (game->obj == 0)
	{
		ft_putstr_fd("\n**************************\n", 2);
		ft_putstr_fd("\n*                        *\n", 2);
		ft_putstr_fd("\n*  * * ! YOU WON !! * *  *\n", 2);
		ft_putstr_fd("\n*                        * \n", 2);
		ft_putstr_fd("\n**************************\n\n", 2);
	}
	else
	{
		ft_putstr_fd("\n**************************\n", 2);
		ft_putstr_fd("\n*                        *\n", 2);
		ft_putstr_fd("\n*  * * CLOSING GAME * *  *\n", 2);
		ft_putstr_fd("\n*                        * \n", 2);
		ft_putstr_fd("\n**************************\n\n", 2);
	}
	free_all(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
	return (0);
}
