# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 17:34:04 by hcaspar           #+#    #+#              #
#    Updated: 2017/03/28 10:57:35 by hcaspar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c exit.c hooks.c draw.c opencl.c func.c

SRCS_DIR = srcs/

OBJS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

INCS_DIR = includes libft/includes

INCS = $(addprefix -I , $(INCS_DIR))

CFLAGS = -Wall -Werror -Wextra $(INCS)

FLAGS = $(CFLAGS) -L libft/ -lft -framework OpenCL \
		-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit \

CC = gcc

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

lib:
	make -C libft/

clean:
	rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
