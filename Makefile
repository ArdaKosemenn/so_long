NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
FREAMS = -framework OpenGL -framework AppKit

MLX = ./mlx/libmlx.a
LIBFT = ./ft_libft/libft.a
GNL = ./get_next_line/get_next_line.a
PRNTF = ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME): *.o $(MLX) $(LIBFT) $(GNL) $(PRNTF)
	$(CC) $(FLAGS) -o $(NAME) *.o $(MLX) $(LIBFT) $(GNL) $(FREAMS) $(PRNTF)

*.o: *.c
	$(CC) $(FLAGS) -c *.c

$(MLX):
	@make -C ./mlx

$(LIBFT):
	@make -C ./ft_libft

$(GNL):
	@make -C ./get_next_line

$(PRNTF):
	@make -C ./ft_printf

clean:
	rm -f *.o
	@make clean -C ./mlx
	@make clean -C ./ft_libft
	@make clean -C ./get_next_line
	@make clean -C ./ft_printf

fclean: clean
	rm -f so_long
	@make fclean -C ./ft_libft
	@make fclean -C ./get_next_line
	@make fclean -C ./ft_printf

re:fclean all