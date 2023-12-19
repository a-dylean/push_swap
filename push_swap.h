#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct	s_stack
{
    int			num;
    int			index;
    struct s_stack    *next;
}				t_stack;

void ft_errors_check(int argc, char **argv);
void ft_char_check(int argc, char **argv);

#endif