/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:16:43 by phbarrad          #+#    #+#             */
/*   Updated: 2019/07/23 11:37:52 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			fill_int_tab(int **tab, char *str, t_data *data)
{
	int			i;
	int			x;
	int			y;

	x = 0;
	y = 0;
	i = data->lun + 1;
	while (str[i])
	{
		if (str[i] == data->c_vide)
			tab[y][x] = 1;
		else if (str[i] == data->obst)
			tab[y][x] = 0;
		else if (str[i] == '\n')
		{
			tab[y][x] = -1;
			y++;
			x = -1;
		}
		x++;
		i++;
	}
}

void			create_int_map(char *str, t_data *data)
{
	int			**i_map;
	int			i;

	i = -1;
	if (!(i_map = malloc(sizeof(int *) * (data->nbr_line + 2))))
		return ;
	while (++i < data->nbr_line)
	{
		if (!(i_map[i] = malloc(sizeof(int) * (data->size_line + 2))))
			return ;
	}
	fill_int_tab(i_map, str, data);
	solve_int_map(i_map, data);
	create_nchar_map(i_map, data);
	i = -1;
	while (++i < data->nbr_line)
		free(i_map[i]);
}
