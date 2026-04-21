NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c \
          print_digits.c \
	  print_pointer.c \
	  print_str.c 
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I . -c $< -o $@

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
