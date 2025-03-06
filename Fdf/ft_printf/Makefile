#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 15:14:14 by ekeller-@st       #+#    #+#              #
#    Updated: 2025/03/06 17:42:59 by ekeller-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = \
ft_putnbr.c \
ft_printf.c \

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:%.c=%.o)

INCLUDES = 	ft_printf.h

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