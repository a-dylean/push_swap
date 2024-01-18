CC = 		cc
CFLAGS = 	-Wall -Wextra -Werror
NAME = 		push_swap
LIBFT = 	libft/libft.a
PRINTF = 	libft/ft_printf/ft_printf.a
INCLUDES = 	-I includes -I libft -I libft/ft_printf
SRC = 		src/errors_check.c src/fill_stack_b.c src/helper_funcs.c \
			src/instructions.c src/manipulate_input.c src/push_swap.c src/refill_stack_a.c \
			src/sorting.c src/stack_operations_1.c src/stack_operations_2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) -L libft -lft -L libft/ft_printf -lftprintf

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C libft/ft_printf

clean:
	make clean -C libft
	make clean -C libft/ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C libft/ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
