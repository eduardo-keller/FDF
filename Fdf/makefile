# Name of the final executable
NAME = fdf

# Source files for fdf
SRC = draw.c fdf.c hooks.c limits.c points.c start.c

# Compiler and flags
CC = cc -g
FLAGS = -Wall -Wextra -Werror

# Object files (will be automatically generated from the source files)
OBJECTS = $(SRC:%.c=%.o)

# Include directories
INCLUDES = -Ilibft -I.

# Libraries to link against
LIBS = -Llibft -lft -L. -lmlx_Linux -lm -lX11 -lXext

# Clean-up command
RM = rm -f

# Default target: compile the executable
all: $(NAME)

# Compile libft (ensure libft is up-to-date by calling its Makefile)
libft/libft.a:
	$(MAKE) -C libft

# Create the executable by compiling the object files and linking with libraries
$(NAME): libft/libft.a $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME) $(LIBS)

# Compile object files from source files (FIXED: Added $(INCLUDES))
%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

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
