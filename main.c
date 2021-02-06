/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:01:34 by phbarrad          #+#    #+#             */
/*   Updated: 2019/07/23 11:57:07 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int				main(int ac, char **av)
{
	int			i;
	t_data		*data;
	int			e;

	if (ac == 1)
	{
		data = malloc(sizeof(t_data));
		if (g_stdin("map_bsq.txt", data) == -1)
			write(2, "map error\n", 10);
		free(data);
	}
	i = 1;
	while (i < ac)
	{
		data = malloc(sizeof(t_data));
		e = ft_open_file(av[i], data);
		if (e == -1)
			write(2, "map error\n", 10);
		if (i + 1 < ac && e != -1)
			write(1, "\n", 1);
		free(data);
		i++;
	}
	return (0);
}
