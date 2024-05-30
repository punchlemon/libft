# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 19:53:52 by retanaka          #+#    #+#              #
#    Updated: 2024/05/30 10:28:18 by retanaka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
INCLUDES		=	libft.h
SRC_DIR			=
BONUS_SRC_DIR	=
OBJ_DIR			=	obj/
BONUS_OBJ_DIR	=	bonus_obj/
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
IFLAGS			=	-I $(INCLUDES)
RM				=	rm -f
AR				=	ar rcs

# Colors
DEF_COLOR		=	\033[0;39m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m

SRC_FILES		=	ft_isalpha \
					ft_isdigit \
					ft_isalnum \
					ft_isascii \
					ft_isprint \
					ft_strlen \
					ft_memset \
					ft_bzero \
					ft_memcpy \
					ft_memmove \
					ft_strlcpy \
					ft_strlcat \
					ft_toupper \
					ft_tolower \
					ft_strchr \
					ft_strrchr \
					ft_strncmp \
					ft_memchr \
					ft_memcmp \
					ft_strnstr \
					ft_atoi \
					ft_calloc \
					ft_strdup \
					ft_substr \
					ft_strjoin \
					ft_strtrim \
					ft_split \
					ft_itoa \
					ft_strmapi \
					ft_striteri \
					ft_putchar_fd \
					ft_putstr_fd \
					ft_putendl_fd \
					ft_putnbr_fd \

BONUS_SRC_FILES	=	ft_lstnew \
					ft_lstadd_front \
					ft_lstsize \
					ft_lstlast \
					ft_lstadd_back \
					ft_lstdelone \
					ft_lstclear \
					ft_lstiter \
					ft_lstmap \

SRCS			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
BONUS_SRCS		=	$(addprefix $(BONUS_SRC_DIR), $(addsuffix .c, $(BONUS_SRC_FILES)))
OBJS			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
BONUS_OBJS		=	$(addprefix $(BONUS_OBJ_DIR), $(addsuffix .o, $(BONUS_SRC_FILES)))
OBJ_FLAG		=	.obj_dir_exitsts
BONUS_OBJ_FLAG	=	.bonus_obj_dir_exitsts

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(AR) $(NAME) $(OBJS)
				@ranlib $(NAME)
				@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"

bonus:			$(NAME) $(BONUS_OBJS)
				@$(AR) $(NAME) $(BONUS_OBJS)
				@ranlib $(NAME)
				@echo "$(GREEN)Libft bonus compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_FLAG)
				@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
				@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c | $(BONUS_OBJ_FLAG)
				@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
				@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_FLAG):
				@mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_FLAG):
				@mkdir -p $(BONUS_OBJ_DIR)

clean:
				@$(RM) -r $(OBJ_DIR)
				@$(RM) -r $(BONUS_OBJ_DIR)
				@echo "$(BLUE)libft objects files cleaned!$(DEF_COLOR)"

fclean:         clean
				@$(RM) $(NAME)
				@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:				fclean all
				@echo "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)"

norm:
				@norminette $(SRCS) $(INCLUDES) $(BONUS_SRCS) | grep -v Norme -B1 || true

.PHONY: all clean fclean re bonus norm
