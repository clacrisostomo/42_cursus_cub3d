# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 01:42:23 by csantos-          #+#    #+#              #
#    Updated: 2021/04/20 01:43:58 by csantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
MLX = libmlx.a
LIBFT = libft.a
CC = clang
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework Appkit
MLX_PATH = mlxopengl
LIBFT_PATH = libft
SRC = cub3d.c
OBJECTS = cub3d.o

all: $(NAME)

$(NAME): $(OBJECTS) $(MLX)
	@$(CC) $(FLAGS) -fsanitize=address -g -o $(NAME) $(OBJECTS) -L $(MLX_PATH) $(MLX_FLAGS)

$(MLX):
	make -C $(MLX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJECTS): $(SRC)
	@$(CC) $(FLAGS) -g -c $(SRC)

git:
	git add .
	git commit -m "updating"
	git push

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS) $(NAME)
