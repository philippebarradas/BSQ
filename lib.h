/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodjian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:06:17 by dodjian           #+#    #+#             */
/*   Updated: 2019/07/20 18:30:04 by phbarrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "ft.h"

int		ft_create_map();
char	*ft_create_dict(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strdup(char *src);
#endif
