CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = bsq
SRCS = #file
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