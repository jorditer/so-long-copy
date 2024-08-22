# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antandre <antandre@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 15:56:18 by antandre          #+#    #+#              #
#    Updated: 2024/07/17 12:56:07 by antandre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Tool and flag definitions
RM = rm -f                 # Command to remove files
MKDIR_P = mkdir -p         # Command to create directories

CC = cc                    # C compiler
CCFLAGS = -Wall -Wextra -Werror # Compiler flags
LIBMLX := ./lib/MLX42

# Target definitions
NAME = so_long

SRC = $(shell find src -name "*.c")
OBJ = $(patsubst src/%.c,bin/%.o,$(SRC))
DEPS = $(patsubst src/%.c,bin/%.d,$(SRC))

LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
HEADERS	:= -Iincludes -I $(LIBMLX)/include

# Number of source files
NUM_SRC = $(words $(SRC))

# Default target
all: libmlx $(NAME)             # all target depends on $(NAME)

#Rule to create the graphic library
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# Rule to create the program
$(NAME): $(OBJ)
	@echo "Creating $(NAME)"
	@$(CC) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(NAME) created successfully"

# Rule to compile .c files to .o files in bin/
bin/%.o: src/%.c
	@$(MKDIR_P) $(dir $@)     # Create the directory for the object file if it doesn't exist
	@$(CC) $(CCFLAGS) -MMD -c $< -o $@ $(HEADERS)
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@echo "[$(COUNT)/$(NUM_SRC)] Compiling $<\r"

# Clean up object and dependency files
clean:
	@$(RM) -r bin/            # Remove the bin/ directory
	@rm -rf $(LIBMLX)/build
	@echo "Cleaned up object and dependency files"

# Clean up everything including the static library
fclean: clean
	@$(RM) $(NAME)            # Remove the program
	@echo "Cleaned up $(NAME)"

# Rebuild everything
re: fclean all                # Run fclean and then all

# Include dependency files
-include $(DEPS)

# Declare phony targets
.PHONY: all clean fclean re

# Initialize progress counter
COUNT = 0
