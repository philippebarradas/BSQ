/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:35:16 by dodjian           #+#    #+#             */
/*   Updated: 2019/07/22 20:35:20 by dodjian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int				g_stdin(char *map, t_data *data)
{
	int			file;
	char		buff;

	file = open(map, O_WRONLY | O_CREAT, 0666);
	if (file == -1)
		return (-1);
	while ((read(0, &buff, 1)) && buff != '\0')
		write(file, &buff, 1);
	close(file);
	if (ft_open_file("map_bsq.txt", data) == -1)
		return (-1);
	return (0);
}
