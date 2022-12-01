# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 16:05:40 by zstenger          #+#    #+#              #
#    Updated: 2022/12/01 20:05:59 by zstenger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
LIBFT = libft/libft.a
MLX42 = MLX42/libmlx42.a
GLFW3 = MLX42/glfw_lib/libglfw3.a

SRCS = src/------RANDOMSHIT------

DEF_COLOR = \033[0;39m
RED = \033[1;91m
GREEN = \033[4;92m
CYAN = \033[1;96m
YELLOW = \033[1;33m
PURPLE = \033[1;35m

BWhite = \033[1;37m 

On_Blue = \033[44m

all: $(NAME)

$(NAME):$(GLFW3) $(LIBFT) $(MLX42)
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(CYAN)$(NAME)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o so_long $(SRCS) \
	$(LIBFT) $(MLX42) $(GLFW3) -framework Cocoa -framework OpenGL -framework IOKit
	@echo "$(PURPLE)$(NAME) $(DEF_COLOR)$(GREEN)Compiling done.$(DEF_COLOR)"

$(LIBFT):
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(CYAN)LIBFT. $(DEF_COLOR)"
	make -C ./libft
	@echo "$(PURPLE)LIBFT $(DEF_COLOR)$(GREEN)has been compiled.$(DEF_COLOR)"

$(MLX42):
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(CYAN) MLX42.$(DEF_COLOR)"
	make -C ./MLX42
	@echo "$(PURPLE)MLX42 $(DEF_COLOR)$(GREEN)has been compiled.$(DEF_COLOR)"

$(GLFW3):
	@if [ -d ./MLX42/glfw_lib ]; \
	then echo "$(GREEN)./MLX42/glfw_lib Exists, no further action required.$(DEF_COLOR)"; \
	else \
	echo "$(RED)./MLX42/glfw_lib Doesn't exists.$(DEF_COLOR)"; \
	echo "$(YELLOW)Downloading and Installing GLFW3.$(DEF_COLOR)"; \
	git submodule update --init --recursive --remote && \
	curl -LO https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.MACOS.zip && \
	unzip glfw-3.3.8.bin.MACOS.zip && \
    rm glfw-3.3.8.bin.MACOS.zip && \
	mv glfw-3.3.8.bin.MACOS/lib-universal glfw-3.3.8.bin.MACOS/glfw_lib && \
	mv glfw-3.3.8.bin.MACOS/glfw_lib ./MLX42/ && \
	mv glfw-3.3.8.bin.MACOS/include/GLFW ./MLX42/include && \
	rm -rf glfw-3.3.8.bin.MACOS && \
	echo "$(GREEN)./MLX42/glfw_lib is installed.$(DEF_COLOR)"; \
	fi
	
clean:
	make clean -C ./libft
	make clean -C ./MLX42
	@echo "$(CYAN)MLX42 and libft .o files has been removed.$(DEF_COLOR)"

fclean:
	@echo "$(RED)Deleting objects.$(DEF_COLOR)"
	make fclean -C ./libft
	make fclean -C ./MLX42
	rm -rf MLX42/glfw_lib/ MLX42/include/GLFW/
	@echo "$(CYAN)MLX42, libft .o & .a files and GLFW has been removed.$(DEF_COLOR)"


t: $(NAME)
	@echo "$(RED)RUN TEST ONE, LET'S PLAY A GAME!$(DEF_COLOR)"
	./$(NAME) map/map.ber
	@echo "$(CYAN)YaAaY yOu HaVe Won!$(DEF_COLOR)"
	
t2: $(NAME)
	@echo "$(RED)RUN TEST ONE, LET'S PLAY A GAME!$(DEF_COLOR)"
	./$(NAME) map/big_map.ber
	@echo "$(CYAN)YaAaY yOu HaVe Won!$(DEF_COLOR)"

re: fclean all
	@echo "$(YELLOW)Project has been rebuilt!$(DEF_COLOR)"
	
tre: tclean $(NAME)
tclean:
	rm -rf $(NAME)

.PHONY: all clean fclean test tclean re