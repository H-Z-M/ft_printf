NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		type_field.c \
		type_field2.c \
		ntoa_format.c \
		ntoa_uint.c \
		ntoa_ulong.c \
		out_char.c \
		utility.c 

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<

bonus : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
