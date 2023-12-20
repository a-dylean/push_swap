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

void ft_check_duplicates(t_stack *stack)
{
    t_stack *temp;
    t_stack *temp2;

    temp = stack;
    while (temp)
    {
        temp2 = temp->next;
        while (temp2)
        {
            if (temp->num == temp2->num)
                ft_exit();
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}
int main(int argc, char **argv)
{
    t_stack **stack_a;
    t_stack **stack_b;

    stack_a = (t_stack **)malloc(sizeof(t_stack*));
    *stack_a = NULL;

    //ft_errors_check(argc, argv);
    //initialize lists a and b
    ft_create_list(stack_a, argc, argv);
    //stack_b = ft_create_list(0, NULL);
    
    //check for doubles in list a
    ft_check_duplicates(*stack_a);
    
    int j;
    j = 0;
    for (j = 0; j < 50; j++)
    {
        printf("head_a: %d\n", (*stack_a)->num);
        stack_a = &(*stack_a)->next;
    }
  
    //call sort function
    //free all memory
    return 0;
}
