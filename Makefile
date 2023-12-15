# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clima-fr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 22:39:19 by clima-fr          #+#    #+#              #
#    Updated: 2023/05/17 23:16:16 by clima-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HDRS = push_swap.h
SRC =	src/check_algorithm.c src/check_numbers.c src/ft_atoi_ps.c src/ft_split_functions.c \
		src/general_operations.c src/operations_a.c src/operations_b.c src/operations_ab.c \
		src/outward_algorithm.c src/push_swap.c src/return_algorithm.c src/sort_algorithm.c \
		src/utilities_check_main.c src/utilities_list.c src/utilities_return.c
OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

# Cleans all generated .o files
clean:
	$(RM) $(OBJS)

# Cleans all generated .o and .a files
fclean: clean
	$(RM) $(NAME)

# Cleans all generated .o and .a files + recompiles
re: fclean all

# Phony is a target that will explicitly tell Make to run the function even if you have a file in your directory with the same name
.PHONY: all clean fclean re
