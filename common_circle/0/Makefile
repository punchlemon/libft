NAME = libft.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =\
	libft/ft_isalpha.c\
	libft/ft_isdigit.c\
	libft/ft_isalnum.c\
	libft/ft_isascii.c\
	libft/ft_isprint.c\
	libft/ft_strlen.c\
	libft/ft_memset.c\
	libft/ft_strlcpy.c\
	libft/ft_bzero.c\
	main.c
OBJS = $(SRCS:.c=.o)
HDRS = libft.h

all: $(NAME) clean

$(NAME): $(OBJS)
	@ $(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HDRS)
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@ rm -f $(OBJS)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
