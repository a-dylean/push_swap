#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include "../libft/libft.h"


# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct t_stack
{
	int				num;
	int				index;
	struct t_stack	*next;
}					t_stack;

void				ft_errors_check(int argc, char **argv);
void	ft_char_check(int argc, char **argv);
void				ft_intsize_check(char **argv);
t_stack				*ft_create_node(int num, int index);
void				ft_add_node_back(t_stack **stack, t_stack *new_node);
t_stack				*ft_get_last_node(t_stack *head);
void				ft_create_list(t_stack **stack, int argc, char **argv);
int ft_list_len(t_stack *head);
void				ft_exit(void);
void				ft_check_duplicates(t_stack *stack);
int ft_stack_is_sorted(t_stack *stack);
void ft_sort(t_stack *stack_a, t_stack *stack_b);
void ft_sort_three(t_stack *stack_a, t_stack *stack_b);
void ft_swap(t_stack *stack_a, char stack);

#endif