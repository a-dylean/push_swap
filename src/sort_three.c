#include "../includes/push_swap.h"

void ft_sort_three(t_stack **stack_a)
{
     int first = (*stack_a)->num;
     int second = (*stack_a)->next->num;
     int third = (*stack_a)->next->next->num;

     if (first > second && second < third && first < third)
          ft_sa(*stack_a);
     else if (first > second && second > third && first > third)
     {
          ft_sa(*stack_a);
          ft_rra(&*stack_a);
     }
     else if (first > second && second < third && first > third)
          ft_ra(&*stack_a);
     else if (first < second && second > third && first < third)
     {
          ft_sa(*stack_a);
          ft_ra(&*stack_a);
     }   
     else if (first < second && second > third && first > third)
          ft_rra(&*stack_a);
}

