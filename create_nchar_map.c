/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nchar_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:11:21 by phbarrad          #+#    #+#             */
/*   Updated: 2019/07/23 11:52:01 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		display_finish(char **c_map, t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < data->nbr_line)
	{
		while (c_map[y][x])
		{
			ft_putchar(c_map[y][x]);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
}

void		fill_plein(char **c_map, int x, int y, t_data *data)
{
	int		biggest;
	int		biggest_y;

	biggest_y = data->biggest;
	biggest = data->biggest;
	while (biggest_y >= 1 && y >= 0)
	{
		while (biggest >= 1 && x >= 0)
		{
			c_map[y][x] = data->c_plein;
			biggest--;
			x--;
		}
		biggest = data->biggest;
		x = data->x_big;
		biggest_y--;
		y--;
	}
}

void		fill_char_map(char **c_map, int **i_map, t_data *data)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y < data->nbr_line)
	{
		if (y == data->y_big && x == data->x_big && data->biggest != 0)
			fill_plein(c_map, x, y, data);
		else if (i_map[y][x] >= 1)
			c_map[y][x] = data->c_vide;
		else if (i_map[y][x] == 0)
			c_map[y][x] = data->obst;
		else if (i_map[y][x] == -1 || x >= data->size_line)
		{
			c_map[y][x] = '\0';
			y++;
			x = -1;
		}
		x++;
	}
}

void		create_nchar_map(int **i_map, t_data *data)
{
	char	**c_map;
	int		i;

	i = -1;
	if (!(c_map = malloc(sizeof(char *) * (data->nbr_line + 2))))
		return ;
	while (++i < data->nbr_line)
	{
		if (!(c_map[i] = malloc(sizeof(char) * (data->size_line + 2))))
			return ;
	}
	fill_char_map(c_map, i_map, data);
	display_finish(c_map, data);
	i = -1;
	while (++i < data->nbr_line)
		free(c_map[i]);
}
