# Name of the final executable
NAME = fdf

# Source files for fdf
SRC = draw.c fdf.c hooks.c limits.c points.c start.c

# Compiler and flags
CC = cc
FLAGS = -Wall -Wextra -Werror

# Object files (will be automatically generated from the source files)
OBJECTS = $(SRC:%.c=%.o)

# Include directories (adjust the paths if needed)
INCLUDES = -Ilibft -Iminilibx-linux

# Libraries to link against
LIBS = -Llibft -lft -Lminilibx-linux -lmlx -lm

# Clean-up command
RM = rm -f

# Default target: compile the executable
all: $(NAME)

# Compile libft (ensure libft is up-to-date by calling its Makefile)
libft:
	$(MAKE) -C libft

# Create the executable by compiling the object files and linking with libraries
$(NAME): libft $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME) $(LIBS)

# Compile object files from source files
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJECTS)
	$(MAKE) -C libft clean

# Clean everything (object files and the executable)
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

# Rebuild everything
re: fclean all

# Specify the targets that are not actual files
.PHONY: all clean fclean re libft
