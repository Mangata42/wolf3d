# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/04 17:19:03 by nghaddar          #+#    #+#              #
#    Updated: 2017/09/26 16:16:47 by nghaddar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wolf3d
CC=gcc
SRC= ./srcs/dda_algo.c \
	./srcs/ft_init_fcts.c \
	./srcs/main.c \
	./srcs/parser.c \
	./srcs/draw.c \
	./srcs/hooks.c \
	./srcs/make_it_move.c \
	./srcs/exit_fcts.c \
	./srcs/reticle.c \
	./srcs/parsing_verif.c

OBJ= dda_algo.o \
	 ft_init_fcts.o \
	 main.o \
	 parser.o \
	 draw.o \
	 hooks.o \
	 make_it_move.o \
	 exit_fcts.o \
	 reticle.o \
	 parsing_verif.o

FLAGS= -Wall -Wextra -Werror
LIB= -L ./libs/libft -lft
MLX= -L ./libs/mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@ echo "\033[92m\t\t\t---> ✓ libft created. ✓ <---\033[0m"
	@ make -C ./libs/libft
	@ echo "\033[92m\t---> ✓ wolf3d program has been successfully created. ✓ <---\033[0m"
	@ $(CC) $(FLAGS) $(OBJ) -o $(NAME) $(MLX) $(LIB)
$(OBJ): $(SRC)
	@ $(CC) $(FLAGS) -c $(SRC)
clean:
	@ echo "\033[1;33m---> All .o files cleared. ✓ <---\033[0m"
	@ rm -f $(OBJ)
	@ make -C ./libs/libft clean
fclean: clean
	@ echo "\033[1;33m---> Everything has been cleared. ✓ <---\033[2;00m"
	@ rm -f $(NAME)
	@ make -C ./libs/libft fclean
re: fclean all

.PHONY: clean, fclean, re