# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 01:42:23 by csantos-          #+#    #+#              #
#    Updated: 2021/04/25 23:46:42 by csantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

MLX = libmlx.a
LIBFT = $(LIBFT_PATH)libft.a
CC = clang
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11
LIBFT_FLAGS = -L $(LIBFT_PATH) -lft
MLX_PATH = minilibx-linux
LIBFT_PATH = libft
SRC = cub3d.c
OBJECTS = cub3d.o

all: $(NAME)

$(NAME): $(OBJECTS) $(MLX) $(LIBFT)
	@$(CC) $(FLAGS) -fsanitize=address -g -o $(NAME) $(OBJECTS) -L $(MLX_PATH) $(MLX_FLAGS) -I $(LIBFT_PATH) $(LIBFT_FLAGS)

$(MLX):
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJECTS): $(SRC)
	@$(CC) $(FLAGS) -g -c $(SRC)

git:
	@git add .
	@git commit -m "updating"
	@git push
	@echo "Done!"

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJECTS) $(NAME)

fclean:
	@rm -f $(NAME)
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(OBJECTS) $(NAME)

.PHONY: all clean fclean re bonus rebonus