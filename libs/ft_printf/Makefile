NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -c
RM = rm -rf
MANDATORY = ft_printf.c ft_puthex.c ft_putchar.c ft_putnbr.c ft_putstr.c
O_MAN = $(MANDATORY:%.c=%.o)

all: $(NAME)

$(NAME): $(O_MAN)

%.o : %.c
	$(CC) $(CFLAGS) $<
	ar -rc $(NAME) $@

clean:
	$(RM) *.o

fclean:
	$(RM) *.o $(NAME)

re: fclean all 
