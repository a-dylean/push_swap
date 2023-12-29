#include "../includes/push_swap.h"

static t_stack *find_node_up_to_ceiling(t_stack *stack, int ceiling)
{
    t_stack *min_node = NULL;
    while (stack != NULL) {
        if (stack->num <= ceiling && (min_node == NULL || stack->num < min_node->num)) {
            min_node = stack;
        }
        stack = stack->next;
    }
    return min_node;
}

static int steps_to_node(t_stack *stack, t_stack *node)
{
    int steps = 0;
    while (stack != node) {
        stack = stack->next;
        steps++;
    }
    return steps;
}
void move_to_b(t_stack **stack_a, t_stack **stack_b)
{ 
    int ratio = calculate_ratio(ft_list_len(*stack_a));
    int ceiling = ratio;
        t_stack *node_to_move = find_node_up_to_ceiling(*stack_a, ceiling);
        if (node_to_move == NULL) {
            ceiling *= 2 * ratio;
        }

        int steps_to_top = steps_to_node(*stack_a, node_to_move);
        int steps_to_bottom = ft_list_len(*stack_a) - steps_to_top;

        if (steps_to_top <= steps_to_bottom) {
            for (int i = 0; i < steps_to_top; i++) {
                ft_rotate(stack_a, 'a');
            }
        } else {
            for (int i = 0; i < steps_to_bottom; i++) {
                ft_reverse_rotate(stack_a, 'a');
            }
        }

        ft_push(stack_a, stack_b, 'b');
        //  If the top value in stack_b is smaller than the previous value, rotate stack_b
        if ((*stack_b)->next != NULL && (*stack_b)->num < (*stack_b)->next->num) {
            ft_rotate(stack_b, 'b');
        }
}

void fill_stack_b(t_stack **stack_a, t_stack **stack_b)
{
    while (ft_list_len(*stack_a) > 3) {
        move_to_b(stack_a, stack_b);
    }
    ft_sort_three(&*stack_a);
}

