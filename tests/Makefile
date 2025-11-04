# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/01 00:00:00 by tester            #+#    #+#              #
#    Updated: 2025/11/04 14:06:00 by ivan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_runner

# Directories
SRC_DIR = .
LIBFT_DIR = ..
INCLUDE_DIR = ..

# Source files
TEST_SRCS = test_runner.c \
			test_all.c \
			test_strlen.c \
			test_atoi.c \
			test_isalpha.c \
			test_isdigit.c \
			test_isalnum.c \
			test_isascii.c \
			test_isprint.c \
			test_toupper.c \
			test_tolower.c \
			test_strchr.c \
			test_strrchr.c \
			test_strncmp.c \
			test_strdup.c \
			test_calloc.c \
			test_memcpy.c \
			test_memmove.c \
			test_memset.c \
			test_bzero.c \
			test_memchr.c \
			test_memcmp.c \
			test_strlcpy.c \
			test_strlcat.c \
			test_strnstr.c \
			test_substr.c \
			test_strjoin.c \
			test_strtrim.c \
			test_split.c \
			test_itoa.c \
			test_strmapi.c \
			test_striteri.c \
			test_put_fd.c \
			test_lists.c

# Object files
OBJS = $(TEST_SRCS:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/libft -I$(SRC_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft
LIBFT = $(LIBFT_DIR)/libft.a

# Colors
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

.PHONY: all clean fclean re test run

all: $(NAME)

# Build libft first
$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR) bonus

# Build test runner
$(NAME): $(LIBFT) $(OBJS)
	@echo "$(YELLOW)Linking test runner...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)Test runner built successfully!$(RESET)"

# Compile test object files
%.o: %.c test_runner.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Run tests
test: $(NAME)
	@echo "$(YELLOW)Running tests...$(RESET)"
	@./$(NAME)

run: test

# Clean object files
clean:
	@echo "$(YELLOW)Cleaning test objects...$(RESET)"
	@rm -f $(OBJS)
	@rm -f test_*.txt
	@echo "$(GREEN)Clean complete!$(RESET)"

# Full clean (objects + executable)
fclean: clean
	@echo "$(YELLOW)Removing test runner...$(RESET)"
	@rm -f $(NAME)
	@rm -f test_*.txt
	@echo "$(GREEN)Fclean complete!$(RESET)"

# Rebuild
re: fclean all

# Help
help:
	@echo "Available targets:"
	@echo "  all     - Build test runner"
	@echo "  test    - Build and run tests"
	@echo "  run     - Alias for test"
	@echo "  clean   - Remove object files"
	@echo "  fclean  - Remove object files and executable"
	@echo "  re      - Rebuild everything"
	@echo "  help    - Show this help message"

