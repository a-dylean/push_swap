#include "push_swap.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	res;
	int	isnegative;
	int	i;

	res = 0;
	i = 0;
	isnegative = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-')
		isnegative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res += ((int)str[i] - 48);
		i++;
	}
	if (isnegative)
		return (-res);
	else
		return (res);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *next;

    //ft_errors_check(argc, argv);
    //initialize lists a and b
    stack_a = ft_create_list(argc, argv);
    int j;
    j = 0;
    for (j = 0; j < argc - 1; j++)
    {
        printf("head_a: %d\n", stack_a->num);
        stack_a = stack_a->next;
    }
    //printf("stack_a: %d\n", stack_a->num);
    //check for doubles in list a
    //call sort function
    //free all memory
    return 0;
}
