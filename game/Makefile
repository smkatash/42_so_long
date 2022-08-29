# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 08:31:25 by ktashbae          #+#    #+#              #
#    Updated: 2022/08/29 16:28:12 by ktashbae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRC = main.c map.c actions.c animations.c images.c set_pixels.c utils.c \
enemy.c enemy_utils.c map_utils.c images_to_pxls.c set_pixels_more.c \

GNLSRC = ../gnL/get_next_line.c ../gnL/get_next_line_utils.c \

LIBFTSRC = ../libft/ft_split.c ../libft/ft_strjoin.c ../libft/ft_strncmp.c ../libft/ft_strlen.c \
../libft/ft_putchar_fd.c ../libft/ft_putendl_fd.c ../libft/ft_putstr_fd.c ../libft/ft_putnbr_fd.c ../libft/ft_itoa.c \

OBJ = $(SRC:.c=.o)
GNLOBJ = $(GNLSRC:.c=.o)
LIBFTOBJ = ${LIBFTSRC:.c=.o}
INCLUDE = -L../mlx -lmlx -lz -framework OpenGL -framework AppKit
MLX = libmlx.a 
RM = rm -f
HEADER = so_long.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTOBJ) $(GNLOBJ) $(HEADER)
	@$(MAKE) -C ../mlx
	@cp ../mlx/$(MLX) .
	@$(CC) $(OBJ) $(LIBFTOBJ) $(GNLOBJ) $(INCLUDE) -o $(NAME)
	@echo "\033[0;32m [so_long is compiled.]"

%.o: %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ../mlx
	@$(RM) $(OBJ) $(LIBFTOBJ) $(GNLOBJ) $(MLX)

fclean: clean
	$(RM) $(NAME)

re: fclean all
