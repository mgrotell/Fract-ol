# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msiivone <msiivone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/23 17:28:55 by msiivone          #+#    #+#              #
#    Updated: 2020/01/31 12:43:58 by msiivone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

C = src/initall.c src/keyboard.c src/julia.c src/burningship.c src/mandelbrot.c src/render.c src/main.c

FLAGS = -Wall -Werror -Wextra

IN = /usr/local/include/ libft/libft.a

LI = /usr/local/lib/

FW = -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):
	@make -C libft/
	gcc $(C) -o $(NAME) $(FLAGS) -I $(IN) -L $(LI) -lmlx $(FW)

clean:
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: clean fclean all re
