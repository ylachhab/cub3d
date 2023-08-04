# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 10:39:51 by ylachhab          #+#    #+#              #
#    Updated: 2023/08/02 15:45:05 by ylachhab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = CC

FLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

SRCS =	main.c \
		parcing.c \
		parcing_utils.c \
		parcing_utils1.c \
		parcing_utils2.c \
		parcing_utils3.c \
		parcing_utils4.c \
		draw_map.c \
		moves.c

OBJS = $(SRCS:.c=.o)

all : libft gnl $(NAME)

libft :
	make -C ./libft all

gnl :
	make -C gnl all

%.o: %.c cub3d.h
	$(CC) $(FLAGS) -c $< -o $@


$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) libft/libft.a gnl/libftgnl.a -lmlx -framework OpenGl -framework Appkit -o $(NAME)

clean:
	rm -rf $(OBJS)
	make  -C libft clean
	make  -C gnl clean

fclean:	clean
	rm -rf $(NAME)
	make  -C libft fclean
	make  -C gnl fclean

re : fclean all

.PHONY : libft gnl