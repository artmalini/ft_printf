NAME = libftprintf.a
INCLUDE = ft_printf.h
SRC = *.c libft/*.c
OBJ = *.o

all: $(NAME)

$(NAME):
		gcc -Wall -Werror -Wextra -c $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all