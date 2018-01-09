NAME = libftprintf.a
INCLUDE = ft_printf.h
#SRC = *.c libft/*.c
SRC = *.c
OBJ = *.o

all: $(NAME)

$(NAME):
		gcc -Wall -Werror -Wextra -c $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all