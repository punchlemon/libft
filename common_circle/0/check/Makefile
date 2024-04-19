NAME = libft.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS := $(wildcard ../libft/*.c)\
	$(wildcard ./*.c)
OBJS = $(SRCS:.c=.o)
HDRS = ../libft/libft.h

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
