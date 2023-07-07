/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:37:36 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/05/24 18:22:29 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_zone
{
	int		width;
	int		heigh;
	char	bck_ground;
}	t_zone;

typedef struct s_value
{
	char	c;
	float	x;
	float	y;
	float	radius;
	char	crct;
}	t_value;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	error_message(char *error_str)
{
	if (error_str)
		write(1, error_str, ft_strlen(error_str));
	return (1);
}

int	free_all(FILE *file, char *str)
{
	fclose(file);
	if (str)
		free(str);
	return (1);
}

char	*get_zone(FILE *file, t_zone *zone)
{
	int		i;
	char	*draw_zone;

	if ((i = fscanf(file, "%d %d %c\n", &zone->width, &zone->heigh, &zone->bck_ground)) != 3)
		return (NULL);
	if ((zone->width <= 0 || zone->width > 300))
		return (NULL);
	if ((zone->heigh <= 0 || zone->heigh > 300))
		return (NULL);
	if (!(draw_zone = malloc((zone->heigh * zone->width + 1) * sizeof(*draw_zone))))
		return (NULL);
	draw_zone[zone->width * zone->heigh + 1] = '\0';
	i = 0;
	while (i < zone->heigh * zone->width)
	{
		draw_zone[i] = zone->bck_ground;
		printf("%c", draw_zone[i]);
		i++;
	}
	return (draw_zone);
}

int	drawing(FILE *file, t_zone *zone, char *draw)
{
	t_value	value;
	int		i;

	(void)zone;
	(void)draw;
	if ((i = fscanf(file, "%c %f %f %f %c", &value.c, &value.x, &value.y, &value.radius, &value.crct)) != 5)
		return (1);
	if (value.c != 'c' && value.c != 'C')
		return (1);
	if (value.radius <= 0.00000000)
		return (1);
	printf("\nc %c\n", value.c);
	printf("x %f\n", value.x);
	printf("y %f\n", value.y);
	return (0);
}

int	main(int argc, char **argv)
{
	FILE	*file;
	t_zone	zone;
	char	*draw;

	if (argc != 2)
		return (error_message("Error: argument\n"));
	if (!(file = fopen(argv[1], "r")))
		return (error_message("Error: Operation file corrupted\n"));
	if (!(draw = get_zone(file, &zone)))
		return (free_all(file, draw) && error_message("Error: Operation file corrupted\n"));
	if (drawing(file, &zone, draw))
		return (free_all(file, draw) && error_message("Error: Operation file corrupted\n"));
	return (0);
}
