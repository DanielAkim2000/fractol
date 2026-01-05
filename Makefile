# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/01 17:17:02 by demane            #+#    #+#              #
#    Updated: 2026/01/05 18:16:02 by demane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = events/key_events.c events/mouse_events.c fractals/burning_ship.c fractals/julia.c \
	fractals/mandelbrot.c math/complex.c math/mapping.c mlx/mlx_draw.c math/math_utils.c\
	mlx/mlx_init.c render/color.c render/render.c render/zoom.c render/move.c render/reset.c \
	utils/ft_atod.c utils/free.c utils/exit.c mlx/mlx_destroy.c main.c

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx_lib

MLX = $(MLX_DIR)/libmlx_Linux.a

OBJS = $(SRCS:.c=.o)

MAKE= make
RM = rm
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

all: $(NAME)

$(NAME):$(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(MLX) $(LIBFT)  -lX11 -lXext -lm -lbsd -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) --directory=$(LIBFT_DIR)

$(MLX):
	$(MAKE) --directory=$(MLX_DIR)

clean:
	$(MAKE) --directory=$(LIBFT_DIR) clean
	$(MAKE) --directory=$(MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) --directory=$(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
