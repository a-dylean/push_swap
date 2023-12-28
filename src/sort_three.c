#include "../includes/push_swap.h"

void ft_sort_three(t_stack **stack_a)
{
     int first = (*stack_a)->num;
     int second = (*stack_a)->next->num;
     int third = (*stack_a)->next->next->num;

     if (first > second && second < third && first < third)
          ft_swap(&*stack_a, 'a');
     else if (first > second && second > third && first > third)
     {
          ft_swap(&*stack_a, 'a');
          ft_reverse_rotate(&*stack_a, 'a');
     }
     else if (first > second && second < third && first > third)
          ft_rotate(&*stack_a, 'a');
     else if (first < second && second > third && first < third)
     {
          ft_swap(&*stack_a, 'a');
          ft_rotate(&*stack_a, 'a');
     }   
     else if (first < second && second > third && first > third)
         ft_reverse_rotate(&*stack_a, 'a');
}

