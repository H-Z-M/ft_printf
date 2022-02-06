NAME	=	libftprintf.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRCS_DIR=	./
SRCS	=	ft_printf.c \
			ft_flags.c \
			ft_type.c \
			ft_type2.c \
			ft_forming.c \
			ft_value_len.c \
			ft_out_char.c \
			util_libft.c \
			util.c 
OBJS_DIR=	obj/
OBJ		=	$(SRCS:.c=.o)
OBJS	=	$(addprefix $(OBJS_DIR), $(OBJ))
RM		=	rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(NAME)

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
