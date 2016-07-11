# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 18:24:41 by lnieto-m          #+#    #+#              #
#    Updated: 2016/07/11 15:39:18 by lnieto-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

SRC_PATH = srcs

OBJ_PATH = obj

INC = -I./usr/local/include -I./libft/includes -I./includes

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

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIBFT_PATH = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(LIBFT_PATH) $(OBJ) -o $(NAME) -L/usr/local/lib/ $(LFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	make -C libft/ clean
	rm -rf $(OBJ)
	rm -rf $(OBJ_PATH)

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
