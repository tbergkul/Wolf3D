# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 14:55:32 by tbergkul          #+#    #+#              #
#    Updated: 2020/02/17 13:56:04 by tbergkul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
LIB = libft/libft.a
LIBDIR = libft/
SRC = main.c save_map.c keys.c draw_map.c texture.c
SRCDIR = src/
MLX = /usr/local/lib/libmlx.a
SRCS = $(addprefix $(SRCDIR),$(SRC))
CCFL = gcc -Wall -Wextra -Werror

.PHONY = all $(NAME) clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@$(CCFL) -o $(NAME) $(LIB) $(SRCS) $(MLX) -lmlx -framework OpenGL -framework AppKit
	@rm -rf fdf.dSYM

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
