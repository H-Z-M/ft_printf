NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		flags_field.c \
		width_field.c \
		precision_field.c \
		length_field.c \
		type_field.c \
		type_field2.c \
		ntoa_format.c \
		ntoa_long.c \
		ntoa_long_long.c \
		ftoa.c \
		etoa.c \
		out_char.c \
		utility.c \
		leakdetect.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
