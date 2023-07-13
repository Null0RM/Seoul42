# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojung <hyojung@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 16:55:30 by hyojung           #+#    #+#              #
#    Updated: 2023/02/01 06:02:44 by hyojung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all = $(NAME)

make = make all

$(NAME) : main.o ft_putnbr.o operation.o
	$(CC) $(CFLAGS) -o do-op main.o ft_putnbr.o operation.o

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

ft_putnbr.o : ft_putnbr.c
	$(CC) $(CFLAGS) -c ft_putnbr.c

operation.o : operation.c
	$(CC) $(CFLAGS) -c operation.c

clean :
	$(RM) main.o ft_putnbr.o operation.o

fclean : clean
	$(RM) do-op

re : fclean all