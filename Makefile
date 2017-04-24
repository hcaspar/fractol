# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 17:34:04 by hcaspar           #+#    #+#              #
#    Updated: 2017/04/24 18:53:57 by hcaspar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SDL_DIR = SDL2

FREETYPE_DIR = freetype

TTF_DIR = SDL2_ttf

SDL_SRC_DIR = SDL2-2.0.5

FREETYPE_SRC_DIR = freetype-2.7.1

TTF_SRC_DIR = SDL2_ttf-2.0.14

SDL_INC = $(SDL_DIR)/include/SDL2/

TTF_INC = $(TTF_DIR)/include/

FLAG_TTF = -L $(TTF_DIR)/lib -lSDL2_ttf

FLAG_SDL = `$(SDL_DIR)/sdl2-config --cflags --static-libs`

SRCS = main.c exit.c hooks.c draw.c opencl.c func.c fracts.c sdl.c

SRCS_DIR = srcs/

OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

INCS_DIR = includes libft/includes $(SDL_INC) $(TTF_INC)

INCS = $(addprefix -I , $(INCS_DIR))

CFLAGS = -Wall -Werror -Wextra $(INCS)

UNAME := $(shell uname -s)

ifeq ($(UNAME), Darwin)
	FLAGS = $(CFLAGS) -L libft/ -lft -framework OpenCL
else
	FLAGS = $(CFLAGS) -L libft/ -lft -lOpenCL
endif

CC = gcc

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(FLAG_SDL) $(FLAG_TTF) $(OBJS) -o $(NAME)

lib:
	make -C libft
	make -j6 -C $(SDL_DIR)
	make -C $(SDL_DIR) install
	make -C $(FREETYPE_DIR)
	make -C $(FREETYPE_DIR) install
	make -C $(TTF_DIR)
	make -C $(TTF_DIR) install

config:
	mkdir -p $(SDL_DIR) && mkdir -p $(FREETYPE_DIR) && mkdir -p $(TTF_DIR)
	cd $(SDL_DIR) && ../$(SDL_SRC_DIR)/configure --prefix=$(PWD)/$(SDL_DIR)
	make -j6 -C $(SDL_DIR)
	make -C $(SDL_DIR) install
	cd $(FREETYPE_DIR) && ../$(FREETYPE_SRC_DIR)/configure --prefix=$(PWD)/$(FREETYPE_DIR)
	make -C $(FREETYPE_DIR)
	make -C $(FREETYPE_DIR) install
	cd $(TTF_DIR) && ../$(TTF_SRC_DIR)/configure --prefix=$(PWD)/$(TTF_DIR) \
	--with-freetype-prefix=$(PWD)/$(FREETYPE_DIR) \
	--with-sdl-prefix=$(PWD)/$(SDL_DIR)
	make -C $(TTF_DIR)
	make -C $(TTF_DIR) install

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C $(TTF_DIR) clean
	make -C $(FREETYPE_DIR) clean
	make -C $(SDL_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C $(TTF_DIR) uninstall
	make -C $(FREETYPE_DIR) uninstall
	make -C $(SDL_DIR) uninstall
	rm -rf $(SDL_DIR) && rm -rf $(FREETYPE_DIR) && rm -rf $(TTF_DIR)

re: clean all
