# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 16:05:40 by zstenger          #+#    #+#              #
#    Updated: 2022/12/22 19:17:52 by zstenger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
MLX42 = MLX42/libmlx42.a
GLFW3 = MLX42/glfw_lib/libglfw3.a
SRCS = src/so_long.c src/ft_dfs_utils.c src/ft_error_cases.c \
		src/ft_load_character.c src/ft_load_elements.c src/ft_make_map.c \
		src/ft_map_validator.c src/ft_player_movement.c

OBJS = $(SRCS:.c=.o)

BONUS = src/bonus/so_long_bonus.c src/bonus/ft_so_long_utils_bonus.c \
		src/bonus/ft_dfs_utils_bonus.c src/bonus/ft_enemy_location_bonus.c \
		src/bonus/ft_enemy_movement_bonus.c src/bonus/ft_error_cases_bonus.c \
		src/bonus/ft_load_characters_bonus.c src/bonus/ft_load_elements_bonus.c \
		src/bonus/ft_make_map_bonus.c src/bonus/ft_load_characters2_bonus.c \
		src/bonus/ft_player_movement_bonus.c src/bonus/ft_map_validator_bonus.c \
		src/bonus/ft_moves_to_window_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

# colors for echo messages
DEF_COLOR = \033[0;39m
RED = \033[1;91m
GREEN = \033[4;92m
CYAN = \033[1;96m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
BWhite = \033[1;37m

all: $(NAME)
	
# compiling so_long
$(NAME):$(MLX42) $(OBJS) $(GLFW3) $(LIBFT)
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(CYAN)$(NAME)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) \
	$(LIBFT) $(MLX42) $(GLFW3) -framework Cocoa -framework OpenGL -framework IOKit
	@echo "$(PURPLE)$(NAME) $(DEF_COLOR)$(GREEN)Compiling done.$(DEF_COLOR)"
	@echo "\033[4;34m                                                            \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄▄     ▄███████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀▀██▄  ███     ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███    ███ ███        █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███    ███ ███               \n\
	███████████ ███    ███        ███         ███    ███ ███    ███ ███     ███▄      \n\
	        ███ ███    ███        ███         ███    ███ ███    ███ ███       ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███    ███  ███     ███     \n\
	▄████████▀   ▀██████▀  ██████ ███████▄▄██  ▀██████▀   ▀█    █▀    ▀███████▀      \n\
																				\033[0m$(DEF_COLOR)"
	@echo "                                \033[1;37mMandatory part By: zstenger$(DEF_COLOR)"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# compiling libft
$(LIBFT):
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(CYAN)LIBFT. $(DEF_COLOR)"
	make -C ./libft
	@echo "$(PURPLE)LIBFT $(DEF_COLOR)$(GREEN)has been compiled.$(DEF_COLOR)"

# compiling MLX42
$(MLX42):
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(CYAN) MLX42.$(DEF_COLOR)"
	git submodule update --init --recursive
	make -C ./MLX42
	@echo "$(PURPLE)MLX42 $(DEF_COLOR)$(GREEN)has been compiled.$(DEF_COLOR)"

# downloading, installing and moving GLFW to the correct folder if ther is none
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

# compiling so_long_bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME):$(MLX42) $(BONUS_OBJS) $(GLFW3) $(LIBFT)
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(CYAN)$(BONUS_NAME)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) \
	$(LIBFT) $(MLX42) $(GLFW3) -framework Cocoa -framework OpenGL -framework IOKit
	@echo "$(PURPLE)$(BONUS_NAME) $(DEF_COLOR)$(GREEN)Compiling done.$(DEF_COLOR)"
	@echo "\033[4;34m                                                                                                                            \n\
	  ▄████████  ▄██████▄   ▄██████▄          ▄█          ▄██████▄   ▄██████▄   ▄██████▄   ▄██████▄  ███▄▄▄▄▄     ▄███████▄      \n\
	 ███    ███ ███    ███ ███    ███        ███         ███    ███ ███    ███ ███    ███ ███    ███ ███▀▀▀▀██▄  ███     ███     \n\
	 ███    █▀  ███    ███ ███    ███        ███         ███    ███ ███    ███ ███    ███ ███    ███ ███    ███ ███        █▀      \n\
	 ███        ███    ███ ███    ███        ███         ███    ███ ███    ███ ███    ███ ███    ███ ███    ███ ███               \n\
	███████████ ███    ███ ███    ███        ███         ███    ███ ███    ███ ███    ███ ███    ███ ███    ███ ███     ███▄      \n\
	        ███ ███    ███ ███    ███        ███         ███    ███ ███    ███ ███    ███ ███    ███ ███    ███ ███       ███     \n\
	  ▄█    ███ ███    ███ ███    ███        ███▌     ▄  ███    ███ ███    ███ ███    ███ ███    ███ ███    ███  ███     ███     \n\
	▄████████▀   ▀██████▀   ▀██████▀  ██████ ███████▄▄██  ▀██████▀   ▀██████▀   ▀██████▀   ▀██████▀   ▀█    █▀    ▀███████▀      \n\
																				\033[0m$(DEF_COLOR)"
	@echo "                                                 \033[1;37mBonus Part By: zstenger$(DEF_COLOR)" 

clean:
	@echo "$(RED)Removing .o files.$(DEF_COLOR)"
	$(RM) $(OBJS) $(BONUS_OBJS)
	make clean -C ./libft
	make clean -C ./MLX42
	@echo "$(CYAN)MLX42 and libft, so_long .o files has been removed.$(DEF_COLOR)"

fclean:
	@echo "$(RED)Deleting objects.$(DEF_COLOR)"
	$(RM) $(OBJS) $(NAME) $(BONUS_OBJS) $(BONUS_NAME)
	make fclean -C ./libft
	make fclean -C ./MLX42
	rm -rf MLX42/glfw_lib/ MLX42/include/GLFW/
	@echo "$(CYAN)MLX42, libft, so_long .o & .a files and GLFW has been removed.$(DEF_COLOR)"

# for easier testing to run tests with different maps faster than the speed of light
t: $(NAME)
	@echo "$(RED)RUN TEST 1, LET THE GAME BEGIN!$(DEF_COLOR)"
	./$(NAME) maps/map.ber
	@echo "$(CYAN)\nHow was it? Did you like it?$(DEF_COLOR)"

t2: $(NAME)
	@echo "$(RED)RUN TEST 2, LET THE GAME BEGIN!$(DEF_COLOR)"
	./$(NAME) maps/map2.ber
	@echo "$(CYAN)\nHow was it? Did you like it?$(DEF_COLOR)"

t3: $(NAME)
	@echo "$(RED)RUN TEST 3, LET THE GAME BEGIN!$(DEF_COLOR)"
	./$(NAME) maps/map3.ber
	@echo "$(CYAN)\nHow was it? Did you like it?$(DEF_COLOR)"

t4: $(NAME)
	@echo "$(RED)RUN TEST 4, LET THE GAME BEGIN!$(DEF_COLOR)"
	./$(NAME) maps/map4.ber
	@echo "$(CYAN)\nHow was it? Did you like it?$(DEF_COLOR)"

t5: $(NAME)
	@echo "$(RED)RUN TEST 5, LET THE GAME BEGIN!$(DEF_COLOR)"
	./$(NAME) maps/map5.ber
	@echo "$(CYAN)\nHow was it? Did you like it?$(DEF_COLOR)"

tb: $(BONUS_NAME)
	@echo "$(RED)RUN BONUS TEST 1, LET THE GAME BEGIN!$(DEF_COLOR)"
	./$(BONUS_NAME) maps/mapb.ber
	@echo "$(CYAN)\nHow was it? Did you survive our beloved cat, norminette?$(DEF_COLOR)"

tb2: $(BONUS_NAME)
	@echo "$(RED)RUN BONUS TEST 2, LET THE GAME BEGIN!$(DEF_COLOR)"
	./$(BONUS_NAME) maps/mapb2.ber
	@echo "$(CYAN)\nHow was it? Did you survive our beloved cat, norminette?$(DEF_COLOR)"

tb3: $(BONUS_NAME)
	@echo "$(RED)RUN BONUS TEST 3, LET THE GAME BEGIN!$(DEF_COLOR)"
	./$(BONUS_NAME) maps/mapb3.ber
	@echo "$(CYAN)\nHow was it? Did you survive our beloved cat, norminette?$(DEF_COLOR)"

tb4: $(BONUS_NAME)
	@echo "$(RED)RUN BONUS TEST 4, LET THE GAME BEGIN!$(DEF_COLOR)"
	./$(BONUS_NAME) maps/mapb4.ber
	@echo "$(CYAN)\nHow was it? Did you survive our beloved cat, norminette?$(DEF_COLOR)"

tb5: $(BONUS_NAME)
	@echo "$(RED)RUN BONUS TEST 5, LET THE GAME BEGIN!$(DEF_COLOR)"
	./$(BONUS_NAME) maps/mapb5.ber
	@echo "$(CYAN)\nHow was it? Did you survive our beloved cat, norminette?$(DEF_COLOR)"

tb6: $(BONUS_NAME)
	@echo "$(RED)RUN BONUS TEST 6, LET THE GAME BEGIN!$(DEF_COLOR)"
	./$(BONUS_NAME) maps/mapb6.ber
	@echo "$(CYAN)\nHow was it? Did you survive our beloved cat, norminette?$(DEF_COLOR)"

re: fclean all
	@echo "$(YELLOW)Project has been rebuilt!$(DEF_COLOR)"

# remaking only the so_long executable 
tre: tclean $(BONUS_NAME)
	@echo "$(YELLOW)so_long executable has been rebuilt!$(DEF_COLOR)"

# removing only the the so_long executable
tclean:
	$(RM) $(BONUS_NAME)
	@echo "$(YELLOW)so_long executable has been removed!$(DEF_COLOR)"

.PHONY: all clean fclean t t2 t3 t4 t5 tb tb2 tb3 tb4 tb5 re tre tclean