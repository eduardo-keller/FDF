NAME = libft.a

SRC = ft_split.c libft.c get_next_line.c get_next_line_utils.c ft_putnbr.c ft_printf.c

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:%.c=%.o)

INCLUDES = 	libft.h get_next_line.h ft_printf.h

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