# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phbarrad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 14:02:10 by phbarrad          #+#    #+#              #
#    Updated: 2019/07/22 10:07:12 by dodjian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
NAME	=	BSQ
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
SRC		=	main.c \
			init_data.c \
			solver.c \
			create_int_tab.c \
			create_nchar_map.c \
			ft_check_valid_map.c \
			libzero.c \
			libun.c \
			ft_stdin.c \

OBJ		=	$(SRC:.c=.o)

${NAME}:	${OBJ}
			${CC} ${CFLAGS} -o ${NAME} ${OBJ}

all:	${NAME}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re:		fclean all
