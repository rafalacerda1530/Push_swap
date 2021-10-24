# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 20:49:54 by rarodrig          #+#    #+#              #
#    Updated: 2021/10/23 17:18:21 by rarodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_OBJ = ./obj/
PATH_SRC = ./src/
PATH_UTILS = ./utils/
PATH_LIBFT = ./includes/42_libft/

FILE = $(PATH_SRC)main.c $(PATH_UTILS)swaps.c $(PATH_UTILS)utils.c\

LIBFT = $(PATH_LIBFT)libft.a
CC = clang
CFLAGS = -Wextra -Werror -Wall
RM = rm -rf

OBJ = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJ)%.o, $(FILE)) 

NAME = push_swap

all: make_libft $(NAME)

$(NAME): $(OBJ)
	@echo done!!
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o push_swap

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJ)
	$(CC) $(CFLAGS) -I. -c $< -o $@

make_libft:
	@make -C $(PATH_LIBFT)

clean:
	@$(RM) $(PATH_OBJ)
	@make -C $(PATH_LIBFT) clean
	@echo obj removed!

fclean: clean
	@$(RM) $(NAME)
	@make -C $(PATH_LIBFT) clean fclean
	@echo clean everything

re: fclean all