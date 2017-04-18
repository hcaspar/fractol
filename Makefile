# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 17:34:04 by hcaspar           #+#    #+#              #
#    Updated: 2017/04/18 20:59:27 by hcaspar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SDL_DIR = SDL2-2.0.5

TTF_DIR = SDL2_ttf-2.0.14

SDL_INC = $(SDL_DIR)/include/

TTF_INC = $(TTF_DIR)/include/

FLAG_TTF = -L $(TTF_DIR)/lib -lSDL2_ttf

FLAG_SDL = `$(SDL_DIR)/sdl2-config --cflags --static-libs`

SRCS = main.c exit.c hooks.c draw.c opencl.c func.c fracts.c sdl.c

SRCS_DIR = srcs/

OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

INCS_DIR = includes libft/includes $(SDL_INC) $(TTF_INC)

INCS = $(addprefix -I , $(INCS_DIR))

CFLAGS = -Wall -Werror -Wextra $(INCS)

FLAGS = $(CFLAGS) -L libft/ -lft -framework OpenCL -framework OpenGL \
		-framework AppKit

CC = gcc

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(FLAG_SDL) $(FLAG_TTF) $(OBJS) -o $(NAME)

lib:
	make -C libft/
	make -j6 -C $(SDL_DIR)
	make -C $(TTF_DIR)

config:
	echo "$(SDL_DIR)/configure --prefix=$HOME/fractol/$(SDL_DIR)"
	make -j6 -C $(SDL_DIR)
	make -C $(SDL_DIR) install
	echo "$(TTF_DIR)/configure --prefix=$HOME/fractol/$(TTF_DIR) \
	--with-freetype-prefix=$HOME/fractol/freetype \
	--with-sdl-prefix=$HOME/fractol/$(SDL_DIR)"
	make -C $(TTF_DIR)
	make -C $(TTF_DIR) install

install:
	make -C $(SDL_DIR) install
	make -C $(TTF_DIR) install

uninstall:
	make -C $(TTF_DIR) uninstall
	make -C $(SDL_DIR) uninstall

clean:
	rm -f $(OBJS)
	make -C SDL2-2.0.5/ clean
	make -C SDL2_ttf-2.0.14/ clean

fclean: clean uninstall
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all install
