# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnameki <rnameki@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 13:01:52 by rnameki           #+#    #+#              #
#    Updated: 2023/08/26 21:25:46 by rnameki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRC = $(wildcard ./*.c)
OBJ = $(SRC:.c=.o)
HDR = numbers.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
