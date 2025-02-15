# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jterrada <jterrada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 21:11:29 by jordi             #+#    #+#              #
#    Updated: 2025/02/15 11:17:34 by jterrada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
LDFLAGS = -fsanitize=address
LIBMLX := ./lib/MLX42
LIBFT := ./lib/Libft

NAME = so_long

DIR_SRC = src/
SRC = $(addprefix $(DIR_SRC), delete.c errors.c graphics.c hooks.c \
	logic.c map_checker.c pathfinding.c map_parser.c so_long.c utils.c)

OBJ = $(patsubst src/%.c,bin/%.o,$(SRC))

LIBS := $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm
HEADERS	:= -Iinclude -I $(LIBMLX)/include -I $(LIBFT)/headers

# Number of source files
NUM_SRC = $(words $(SRC))

all: libmlx libft $(NAME)

libmlx: $(LIBMLX)/build/libmlx42.a

$(LIBMLX)/build/libmlx42.a:
	@echo "🛠️  Building MLX42 library..."
	@cmake -Wno-dev -S $(LIBMLX) -B $(LIBMLX)/build -DCMAKE_BUILD_TYPE=Debug > /dev/null 2>&1 && \
	make -C $(LIBMLX)/build -j4 > /dev/null 2>&1
	@echo "✅ MLX42 successfully built!\n"

libft: $(LIBFT)/libft.a

$(LIBFT)/libft.a:
	@echo "🛠️  Building Libft..."
	@$(MAKE) -C $(LIBFT) > /dev/null
	@echo "✅ Libft successfully built!\n"

$(NAME): $(OBJ)
	@echo "🚧 Building $(NAME) executable..."
	@$(CC) $(OBJ) $(LIBS) $(HEADERS) $(LDFLAGS) -o $(NAME)
	@echo "🎉 $(NAME) ready to play!\n"

bin/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(HEADERS)
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@printf "🔨 [%d/%d] Compiling %s\r" $(COUNT) $(NUM_SRC) $<

clean:
	@rm -f -r bin/
	@rm -rf $(LIBMLX)/build
	@$(MAKE) --no-print-directory -C $(LIBFT) clean
	@echo "🧹 Cleaned up object files and build directories!\n"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean
	@echo "🧹 Executable and libraries cleaned!\n"

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft

COUNT = 0