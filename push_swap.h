#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct	t_stack
{
    int			num;
    int			index;
    struct t_stack    *next;
}				t_stack;

void ft_errors_check(int argc, char **argv);
void ft_char_check(int argc, char **argv);
int	ft_atoi(const char *str);
t_stack *ft_create_node(int num, int index);
void	add_node_back(t_stack **stack, t_stack *new_node);
t_stack	*get_last(t_stack *head);
t_stack *ft_create_list(int argc, char **argv);

#endif