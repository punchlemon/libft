# NAME = libft.a
# CC = cc
# AR = ar -rc
# CFLAGS = -Wall -Wextra -Werror
# SRCS := ft_isalpha.c\
# 	ft_isdigit.c\
# 	ft_isalnum.c\
# 	ft_isascii.c\
# 	ft_isprint.c\
# 	ft_strlen.c\
# 	ft_memset.c\
# 	ft_bzero.c\
# 	ft_memcpy.c\
# 	ft_memmove.c\
# 	ft_strlcpy.c\
# 	ft_strlcat.c\
# 	ft_toupper.c\
# 	ft_tolower.c\
# 	ft_strchr.c\
# 	ft_strrchr.c\
# 	ft_strncmp.c\
# 	ft_memchr.c\
# 	ft_memcmp.c\
# 	ft_strnstr.c\
# 	ft_atoi.c\
# 	ft_calloc.c\
# 	ft_strdup.c\
# 	ft_substr.c\
# 	ft_strjoin.c\
# 	ft_strtrim.c\
# 	ft_split.c\
# 	ft_itoa.c\
# 	ft_strmapi.c\
# 	ft_striteri.c\
# 	ft_putchar_fd.c\
# 	ft_putstr_fd.c\
# 	ft_putendl_fd.c\
# 	ft_putnbr_fd.c\

# OBJS = $(SRCS:.c=.o)
# HDRS = libft.h

# all: $(NAME) clean

# $(NAME): $(OBJS)
# 	@ $(AR) $(NAME) $(OBJS)

# %.o: %.c $(HDRS)
# 	@ $(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	@ rm -f $(OBJS)

# fclean: clean
# 	@ rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memccpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_strtok \
		ft_strcmp \
		get_next_line \

FILES_B = 	ft_lstnew \
	  		ft_lstadd_front \
	  		ft_lstsize \
	  		ft_lstlast \
	  		ft_lstadd_back \
	  		ft_lstdelone \
	  		ft_lstclear \
	  		ft_lstiter \
	  		ft_lstmap

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS_B)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re