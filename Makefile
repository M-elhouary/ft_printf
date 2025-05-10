SRC = ft_printf.c handl_int_numbers.c handl_character.c handl_string.c handl_hex.c \
		handl_pointer.c handl_unsigned_numbers.c

OFILES = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
