/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:34:01 by atonkopi          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:31 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_sa(t_stack *stack)
{
    int temp;
      
    if (!stack)
        return;
    temp = stack->num;
    stack->num = stack->next->num;
    stack->next->num = temp;
    ft_printf("sa\n");
}

void ft_sb(t_stack *stack)
{
    int temp;

    if (!stack)
        return;
    temp = stack->num;
    stack->num = stack->next->num;
    stack->next->num = temp;
    ft_printf("sb\n");
}

void ft_ss(t_stack *stack_a, t_stack *stack_b)
{
    int temp1;
    int temp2;

    if (!stack_a || !stack_b)
        return;
    temp1 = stack_a->num;
    stack_a->num = stack_a->next->num;
    stack_a->next->num = temp1;
    temp2 = stack_b->num;
    stack_b->num = stack_b->next->num;
    stack_b->next->num = temp2;
    ft_printf("ss\n");
}

void ft_pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;

    if (*stack_a == NULL)
        return;

    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = *stack_b;
    *stack_b = temp;
    ft_printf("pb\n");
}

void ft_pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;

    if (*stack_b == NULL)
        return;

    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = *stack_a;
    *stack_a = temp;
    ft_printf("pa\n");
}

void ft_ra(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    first = *stack;
    *stack = (*stack)->next;
    first->next = NULL;
    last = ft_get_last_node(*stack);
    last->next = first;
    ft_printf("ra\n");
}

void ft_rb(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    first = *stack;
    *stack = (*stack)->next;
    first->next = NULL;
    last = ft_get_last_node(*stack);
    last->next = first;
    ft_printf("rb\n");
}

void ft_rr(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first1;
    t_stack *last1;
    t_stack *first2;
    t_stack *last2;

    if (*stack_a == NULL || (*stack_a)->next == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
        return;
    first1 = *stack_a;
    *stack_a = (*stack_a)->next;
    first1->next = NULL;
    last1 = ft_get_last_node(*stack_a);
    last1->next = first1;
    first2 = *stack_b;
    *stack_b = (*stack_b)->next;
    first2->next = NULL;
    last2 = ft_get_last_node(*stack_b);
    last2->next = first2;
    ft_printf("rr\n");
}

void ft_rrb(t_stack **stack)
{
    t_stack *prev;
    t_stack *last;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    last = *stack;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
    ft_printf("rrb\n");
}

void ft_rra(t_stack **stack)
{
    t_stack *prev;
    t_stack *last;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    last = *stack;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
    ft_printf("rra\n");
}

void ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *prev1;
    t_stack *last1;
    t_stack *prev2;
    t_stack *last2;

    if (*stack_a == NULL || (*stack_a)->next == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
        return;
    last1 = *stack_a;
    while (last1->next != NULL) {
        prev1 = last1;
        last1 = last1->next;
    }
    prev1->next = NULL;
    last1->next = *stack_a;
    *stack_a = last1;
    last2 = *stack_b;
    while (last2->next != NULL) {
        prev2 = last2;
        last2 = last2->next;
    }
    prev2->next = NULL;
    last2->next = *stack_b;
    *stack_b = last2;
    ft_printf("rrr\n");
}

