# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 16:51:29 by amakhiny          #+#    #+#              #
#    Updated: 2018/01/27 16:51:36 by amakhiny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB_DIR = libft/

SRC_FILES = ft_printf.c build_char_strchar.c build_float_join_str.c build_floats.c build_mantissa_with_build_float.c \
			fill_flag_with_precis.c fill_length_type_hex.c nbr_types_cast.c output_chars.c parse_arg.c print_atoi_nbr.c \
			prf_itoa_base.c print_str_with_flags.c ft_strlendup.c str_join_float.c fixsmall.c
LIBFT_FILES = ft_strchr.c ft_memalloc.c ft_bzero.c ft_strcpy.c ft_strncpy.c ft_strlen.c ft_strcat.c ft_strcmp.c ft_strdup.c		

LIBFT = $(addprefix $(LIB_DIR), $(LIBFT_FILES))
OBJ = $(SRC_FILES:.c=.o) $(LIBFT_FILES:.c=.o)
INC = -Iincludes/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec."
	@gcc -c $(FLAGS) $(SRC_FILES) $(LIBFT) $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "(•̀ᴗ•́)و $(NAME) generated!".

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
