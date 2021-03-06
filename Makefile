# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcollet <gcollet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 11:07:37 by gcollet           #+#    #+#              #
#    Updated: 2021/07/29 11:26:03 by gcollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fractol.a
SRCS 	= srcs/main.c srcs/fractal.c srcs/make_fractal.c srcs/control.c
OBJS 	= ${SRCS:.c=.o}
HEADER	= -I./includes/
MAIN	= srcs/main.c

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -Imlx -c $< -o $(<:.c=.o)

$(NAME):	${OBJS}
					@echo "\033[32m----Creating fractal----"
					@make re -C ./libft
					@cp libft/libft.a ./$(NAME)
					@ar -rcs ${NAME} ${OBJS}
					@$(CC) -lmlx -framework OpenGL -framework AppKit $(NAME) ${MAIN} -o fractol
					@echo "\033[32mFractal Completed! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

all: 		${NAME}

bonus:		${NAME}

clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)
					@rm -f fractol
					@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

war:
					@echo "This is a bad choice, what about peace?"

.PHONY: all clean fclean re bonus
