CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = bsq
SRCS = ft_check_map.c ft_check_map2.c ft_map_to_input.c ft_others.c ft_print_map.c ft_read.c ft_solve.c ft_split.c main.c
OBJS = ${SRCS:.c=.o}
HEADER = ft_bsq.h

all: $(NAME)

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re