/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:44:28 by phbarrad          #+#    #+#             */
/*   Updated: 2019/07/21 20:28:09 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int			plus_petit(int **i_map, int y, int x)
{
	if (x == 0 || y == 0)
		return (0);
	if (x > 0 && y > 0 && i_map[y][x - 1] <= i_map[y - 1][x]
	&& i_map[y][x - 1] <= i_map[y - 1][x - 1])
		return (i_map[y][x - 1]);
	if (x > 0 && y > 0 && i_map[y - 1][x - 1] <= i_map[y - 1][x]
	&& i_map[y - 1][x - 1] <= i_map[y][x - 1])
		return (i_map[y - 1][x - 1]);
	if (x > 0 && y > 0 && i_map[y - 1][x] <= i_map[y][x - 1]
	&& i_map[y - 1][x] <= i_map[y - 1][x - 1])
		return (i_map[y - 1][x]);
	return (i_map[y][x]);
}

void		solve_int_map(int **i_map, t_data *data)
{
	int		x;
	int		y;

	y = -1;
	x = -1;
	data->y_big = 0;
	data->x_big = 0;
	data->biggest = i_map[0][0];
	while (++y < data->nbr_line)
	{
		while (++x < data->size_line - 1)
		{
			if (i_map[y][x] != 0)
			{
				i_map[y][x] = i_map[y][x] + plus_petit(i_map, y, x);
				if (i_map[y][x] > data->biggest)
				{
					data->biggest = i_map[y][x];
					data->y_big = y;
					data->x_big = x;
				}
			}
		}
		x = -1;
	}
}
