NAME = gnl.a

SRC = \
get_next_line_utils.c \
get_next_line.c \

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:%.c=%.o)

INCLUDES = 	get_next_line.h

RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)

%.o:%.c $(INCLUDES)
	${CC} ${FLAGS} -c $< -o $@
	ar rc $(NAME) $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re