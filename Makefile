# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcollet <gcollet@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 11:07:37 by gcollet           #+#    #+#              #
#    Updated: 2021/07/09 12:08:38 by gcollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fractol.a
SRCS 	= srcs/test.c srcs/make_circle.c srcs/make_square.c srcs/make_triangle.c
OBJS 	= ${SRCS:.c=.o}
SRCS_B	= 
OBJS_B	= ${SRCS_B:.c=.o}
HEADER	= includes/

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

.c.o:		%.o : %.c
					${CC} ${CFLAGS} -g -I ${HEADER} -Imlx -c $< -o $(<:.c=.o)

$(NAME):	${OBJS}
					$(CC) -lmlx -framework OpenGL -framework AppKit -o $(NAME) ${OBJS}

all: 		${NAME}

bonus:		${OBJS} ${OBJS_B}
					ar rc ${NAME} ${OBJS} ${OBJS_B}

clean:
					rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus