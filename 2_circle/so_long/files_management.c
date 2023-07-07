/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:59:44 by theophilebr       #+#    #+#             */
/*   Updated: 2022/04/26 12:54:54 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"

int	map_validity_parsing(char *s, int i, int width, int heigth)
{	
	int	j;

	j = 0;
	if (i == 0 || i == heigth - 1)
	{
		while (s[j] == '1')
			j++;
		if (s[j] != '\0' && s[j] != '\n')
			return (0);
	}
	if (s[0] != '1' || s[width - 1] != '1')
		return (0);
	j = 0;
	while (s[j])
	{
		if (s[j] != '0' && s[j] != '1' && s[j] != 'C'
			&& s[j] != 'E' && s[j] != 'P' && s[j] != '\n')
			return (0);
		j++;
	}
	return (1);
}

int	symbol_check(char *tmp, int *c, int *e, int *p)
{
	int	i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		if (tmp[i] == 'C')
			*c += 1;
		if (tmp[i] == 'E')
			*e += 1;
		if (tmp[i] == 'P')
			*p += 1;
		i++;
	}
	return (1);
}

int	map_validity_check(char **tmp, int heigth, t_game *game)
{
	int	i;
	int	c;
	int	e;
	int	p;

	e = 0;
	p = 0;
	c = 0;
	i = -1;
	while (++i < heigth)
	{
		if (ft_strlen(tmp[i]) != ft_strlen(tmp[0]))
			return (0);
		if (!(map_validity_parsing(tmp[i], i, ft_strlen(tmp[0]), heigth)))
			return (0);
		if (!(symbol_check(tmp[i], &c, &e, &p)))
			return (0);
	}
	game->obj = c;
	if (c == 0 || e == 0 || p != 1)
		return (0);
	return (1);
}

int	nbr_lign(char **argv, t_game *game)
{
	int		heigth;
	int		fd;
	char	*str;

	heigth = 0;
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	if (!str)
	{
		ft_putstr_fd("\nerror[arguments] : NOT A MAP\n\n", 1);
		return (0);
	}
	game->blk_wd = ft_strlen(str);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		heigth++;
		free(str);
	}
	game->blk_hg = heigth;
	return (heigth);
}

char	**map_load(char **argv, t_game *game)
{
	char	**tmp;
	int		fd;
	int		i;
	int		heigth;

	heigth = nbr_lign(argv, game);
	if (heigth == 0)
		return (NULL);
	tmp = malloc((heigth) * sizeof(*tmp));
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i < heigth)
	{
		tmp[i] = get_next_line(fd);
		i++;
	}
	game->obj = 0;
	if (!map_validity_check(tmp, heigth, game))
		return (0);
	return (tmp);
}
