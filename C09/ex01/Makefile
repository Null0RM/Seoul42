# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 20:30:39 by hyojung           #+#    #+#              #
#    Updated: 2023/02/01 03:44:45 by hyojung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I includes
NAME = libft.a
RM = rm -rf

all : $(NAME)

make : make all

$(NAME) :  ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o includes/ft.h
	ar -rcs $(NAME) srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
	ranlib libft.a

ft_putchar.o : srcs/ft_putchar.c
	$(CC) $(CFLAGS) -c -o srcs/ft_putchar.o srcs/ft_putchar.c

ft_swap.o : srcs/ft_swap.c
	$(CC) $(CFLAGS) -c -o srcs/ft_swap.o srcs/ft_swap.c

ft_putstr.o : srcs/ft_putstr.c
	$(CC) $(CFLAGS) -c -o srcs/ft_putstr.o srcs/ft_putstr.c

ft_strlen.o : srcs/ft_strlen.c
	$(CC) $(CFLAGS) -c -o srcs/ft_strlen.o srcs/ft_strlen.c

ft_strcmp.o : srcs/ft_strcmp.c
	$(CC) $(CFLAGS) -c -o srcs/ft_strcmp.o srcs/ft_strcmp.c

clean :
	${RM} srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o

fclean : clean
	${RM} libft.a

re : fclean all

.PHONY : ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o all clean fclean re