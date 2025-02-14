# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jordi <jordi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 21:11:29 by jordi             #+#    #+#              #
#    Updated: 2025/02/14 23:00:57 by jordi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Tool and flag definitions
RM = rm -f
MKDIR_P = mkdir -p

CC = cc
CCFLAGS = -Wall -Wextra -Werror -DDEBUG=1 -g
LIBMLX := ./lib/MLX42
LIBFT := ./lib/Libft

NAME = so_long

DIR_SRC = src/
SRC = $(addprefix $(DIR_SRC), delete.c errors.c graphics.c hooks.c \
    logic.c map_checker.c pathfinding.c map_parser.c so_long.c utils.c)

OBJ = $(patsubst src/%.c,bin/%.o,$(SRC))

LIBS := $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm
HEADERS	:= -Iinclude -I $(LIBMLX)/include -I $(LIBFT)/include

# Number of source files
NUM_SRC = $(words $(SRC))

all: libmlx libft $(NAME)

libmlx: $(LIBMLX)/build/libmlx42.a

$(LIBMLX)/build/libmlx42.a:
	@echo "Building libmlx..."
	@cmake -Wno-dev -S $(LIBMLX) -B $(LIBMLX)/build -DCMAKE_BUILD_TYPE=Debug > /dev/null 2>&1 && \
	make -C $(LIBMLX)/build -j4 > /dev/null 2>&1
	@echo "libmlx built successfully"

libft: $(LIBFT)/libft.a

$(LIBFT)/libft.a:
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT) > /dev/null
	@echo "libft built successfully"

$(NAME): $(OBJ)
	@echo "Creating $(NAME)"
	@$(CC) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(NAME) created successfully"


bin/%.o: src/%.c
	@$(MKDIR_P) $(dir $@)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(HEADERS)
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@echo "[$(COUNT)/$(NUM_SRC)] Compiling $<\r"

clean:
	@$(RM) -r bin/
	@rm -rf $(LIBMLX)/build
	@$(MAKE) --no-print-directory -C $(LIBFT) clean
	@echo "Cleaned up object and dependency files"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean
	@echo "Cleaned up $(NAME)"

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft

COUNT = 0
