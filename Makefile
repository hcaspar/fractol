# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 17:34:04 by hcaspar           #+#    #+#              #
#    Updated: 2017/04/18 14:43:16 by hcaspar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c exit.c hooks.c draw.c opencl.c func.c fracts.c sdl.c

SRCS_DIR = srcs/

OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

INCS_DIR = includes libft/includes SDL2-2.0.5/include

INCS = $(addprefix -I , $(INCS_DIR))

SDL_DIR = SDL2-2.0.5

SDL_LIB = $(SDL_DIR)/build/.libs/libSDL2.a

SDL_INC = $(SDL_DIR)/include/

FLAG_SDL = -I/$(SDL_INC) $(SDL_LIB) -framework Cocoa -framework CoreAudio \
		-framework AudioToolbox -framework ForceFeedback -framework CoreVideo \
		-framework Carbon -framework IOKit -liconv

CFLAGS = -Wall -Werror -Wextra $(INCS)

FLAGS = $(CFLAGS) -L libft/ -lft -framework OpenCL -framework OpenGL \
		-framework AppKit

CC = gcc

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(FLAG_SDL) $(OBJS) -o $(NAME)

lib:
	make -C libft/
	make -C SDL2-2.0.5/

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C SDL2-2.0.5/ clean

re: fclean all
