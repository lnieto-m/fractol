# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 18:24:41 by lnieto-m          #+#    #+#              #
#    Updated: 2016/01/26 16:08:32 by lnieto-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -lmlx -framework OpenGl -framework AppKit -lm

NAME = fractol

SRC_NAME = main.c \
		   key_r.c \
		   expose_hook.c \
		   mouse_hook.c \
		   pointer_motion.c \
		   image_pixel_put.c \
		   mandelbrot.c \
		   julia.c \
		   burning_ship.c \
		   loop_hook.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

LIBFT_PATH = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_NAME)
	make -C libft/
	$(CC) $(LIBFT_PATH) $(OBJ_NAME) -o $(NAME) -L/usr/local/lib/ $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I./usr/local/include -I./libft/includes -c $<

clean:
	make -C libft/ clean
	rm -rf $(OBJ_NAME)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

norme:
	@echo "* Norme fractol"
	norminette $(SRC_NAME)
	@echo "* Norme Libft"
	make -C libft/ norme

.PHONY: clean fclean re all
