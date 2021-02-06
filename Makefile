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
SRC		=	srcs/main.c \
			srcs/init_data.c \
			srcs/solver.c \
			srcs/create_int_tab.c \
			srcs/create_nchar_map.c \
			srcs/ft_check_valid_map.c \
			srcs/libzero.c \
			srcs/libun.c \
			srcs/ft_stdin.c \

OBJ		=	$(SRC:.c=.o)

${NAME}:	${OBJ}
			${CC} ${CFLAGS} -o ${NAME} ${OBJ}

all:	${NAME}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re:		fclean all
