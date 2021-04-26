# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 19:49:52 by csantos-          #+#    #+#              #
#    Updated: 2021/02/25 12:42:22 by csantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIB			= ar -rcs
LIB1		= ranlib
RM			= /bin/rm -f

INCLUDE		= libft.h
SRCS		= ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_isalnum.c \
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_strncmp.c ft_toupper.c ft_tolower.c ft_strlen.c \
				ft_strlcat.c ft_putnbr_fd.c ft_strlcpy.c ft_strchr.c \
				ft_strrchr.c ft_strnstr.c ft_memset.c ft_bzero.c \
				ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
				ft_memmove.c ft_atoi.c ft_strdup.c ft_calloc.c\
				ft_itoa.c ft_substr.c ft_strjoin.c ft_strmapi.c\
				ft_strtrim.c ft_split.c

OBJS		= $(SRCS:.c=.o)

BONUS_SRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstiter.c ft_lstdelone.c ft_lstclear.c \
				ft_lstmap.c

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB) $(NAME) $(OBJS)
			$(LIB1) $(NAME)

bonus:		$(NAME) $(BONUS_OBJS)
			$(LIB) $(NAME) $(BONUS_OBJS)
			$(LIB1) $(NAME)

git:
			git add .
			git commit -m "updating norminette v3"
			git push

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
