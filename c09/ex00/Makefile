TARGET = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/%.c
OBJS = $(SRCS:.c=.o)
INCLUDES = includes/ft.h


all: $(TARGET)

$(TARGET): $(OBJS)
	ar r $@ $^

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET) 

re: fclean all
