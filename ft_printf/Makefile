NAME= libftprintf.a
SRCS= ft_lower.c ft_pointer.c\
	 ft_putchar.c ft_putnbr.c ft_putstr.c ft_unsigned.c\
	 ft_upper.c ft_printf.c

OBJS= $(SRCS:.c=.o)	

CC=gcc

RM= rm -rf

FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean: clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re