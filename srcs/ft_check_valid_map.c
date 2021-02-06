/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:43:56 by dodjian           #+#    #+#             */
/*   Updated: 2019/07/23 11:56:43 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

int			is_val(char c, t_data *data)
{
	if ((c != data->c_vide && c != data->obst) && (c != '\n'))
		return (1);
	if (data->obst == '\n' || data->c_vide == '\n' || data->c_plein == '\n')
		return (1);
	if (data->obst == data->c_vide || data->obst == data->c_plein
	|| data->c_vide == data->c_plein)
		return (1);
	if (c >= 9 && c <= 13 && c != '\n')
		return (1);
	return (0);
}

int			ft_check_valid_map(char *str, t_data *data)
{
	int		i;
	int		nb_bn;
	int		j;

	j = 0;
	nb_bn = 0;
	i = data->lun;
	while (str[++i])
	{
		if (is_val(str[i], data) == 1)
			return (1);
		if (str[i] == '\n')
		{
			nb_bn++;
			if (j != data->size_line - 1)
				return (1);
			j = -1;
		}
		j++;
	}
	if (nb_bn != data->nbr_line ||
	ft_strlen(str) == (data->nbr_line + 1) * data->size_line
	|| str[0] == '\0' || data->size_line == 1)
		return (1);
	return (0);
}
