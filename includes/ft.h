/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phbarrad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:19:50 by phbarrad          #+#    #+#             */
/*   Updated: 2019/07/21 20:42:16 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <libgen.h>
# include "lib.h"

typedef struct	s_data
{
	int			nbr_line;
	int			size_line;
	int			lun;

	char		obst;
	char		c_vide;
	char		c_plein;

	int			biggest;
	int			x_big;
	int			y_big;

}				t_data;

int				ft_open_file(char *av, t_data *data);
void			create_int_map(char *str, t_data *data);
void			create_nchar_map(int **i_map, t_data *data);
int				ft_check_valid_map(char *str, t_data *data);
void			solve_int_map(int **i_map, t_data *data);
int				g_stdin(char *map, t_data *data);

#endif
