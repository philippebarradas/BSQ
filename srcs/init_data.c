/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:12:42 by phbarrad          #+#    #+#             */
/*   Updated: 2019/07/23 11:51:49 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int				f_len(char *str)
{
	int			file;
	char		buff;
	int			i;

	i = 0;
	file = open(str, O_RDONLY);
	if (file == -1)
		return (-1);
	while ((read(file, &buff, 1)) && buff != '\n' && buff != '\0')
		i++;
	close(file);
	return (i);
}

void			fill_data(char *str, char buff, t_data *data, int len)
{
	int			file;
	int			q;
	int			nb;
	int			m;

	nb = 0;
	m = 0;
	q = 0;
	file = open(str, O_RDONLY);
	while ((read(file, &buff, 1)) && nb < 1 && buff != '\0')
	{
		while (((buff >= '0' && buff <= '9')) && q == 0 && --len > 2)
			read(file, &buff, 1);
		if (q == 0)
			data->c_vide = buff;
		if (q == 1)
			data->obst = buff;
		if (q == 2)
			data->c_plein = buff;
		if (buff == '\n')
			nb++;
		q++;
	}
	close(file);
}

int				get_size_line(char *str, t_data *data, int len, int i)
{
	int			file;
	char		buff;
	int			value;
	int			nb;

	nb = 0;
	value = 0;
	file = open(str, O_RDONLY);
	if (file == -1)
		return (-1);
	while ((read(file, &buff, 1)) && (buff >= '0' && buff <= '9')
	&& --len > 2 && len < 11)
		value = value * 10 + (buff - '0');
	close(file);
	file = open(str, O_RDONLY);
	while ((read(file, &buff, 1)) && nb < 2 && buff != '\0')
	{
		buff == '\n' ? nb++ : nb;
		nb == 1 ? i++ : i;
	}
	close(file);
	fill_data(str, buff, data, f_len(str));
	data->nbr_line = value;
	data->size_line = i;
	return (0);
}

int				ft_open_file(char *av, t_data *data)
{
	int			file;
	char		*map;

	data->c_vide = '\n';
	data->obst = '\n';
	data->c_plein = '\n';
	data->lun = f_len(av);
	if (get_size_line(av, data, f_len(av), 0) == -1)
		return (-1);
	if (!(map = malloc(sizeof(char) * ((data->size_line * data->nbr_line)
	+ data->lun + 10))))
		return (-1);
	file = open(av, O_RDONLY);
	if (file == -1)
		return (-1);
	read(file, map, (data->size_line * data->nbr_line) + data->lun + 1);
	map[(data->size_line * data->nbr_line) + data->lun + 1] = '\0';
	if (ft_check_valid_map(map, data) == 1)
		return (-1);
	if (data->nbr_line == 0)
		return (-1);
	create_int_map(map, data);
	free(map);
	return (0);
}
