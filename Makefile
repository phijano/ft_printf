NAME = libftprintf.a
SOURCES = \
	ft_printf.c ft_putchar.c ft_putstr.c ft_putptr.c ft_putnbr.c \
	ft_putunsigned_base.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar crs $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
