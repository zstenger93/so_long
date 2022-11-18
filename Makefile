# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 16:05:40 by zstenger          #+#    #+#              #
#    Updated: 2022/11/18 17:54:04 by zstenger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Game
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -0fast
LIBMLX = ./MLX42

HEADERS = -I. ./MLX42/include/
LIBS = $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm
SRCS = $(shell find ./ -iname "*.c")
OBJS := ${SRCS:;c=.o}



all: libmlx $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean

re: fclean all

.PHONY: all clean fclean re libmlx