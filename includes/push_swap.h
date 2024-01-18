/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:09:15 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/18 15:12:15 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct t_node
{ 
	int				num;
	int				index;
	struct t_node	*next;
}					t_node;

void ft_print_stack(t_node *stack, char stack_name);
void				ft_parse_input(int argc, char **argv, t_node **stack_a);
void				ft_exit(t_node **stack_a);
void				*ft_free_array(char **arr);
int					ft_str_is_empty(char *str);
int					ft_calculate_ratio(int stack_len);
void				ft_populate_stack(char **argv, t_node **stack_a);
int					ft_chars_check(char *str);
int					ft_duplicates_check(t_node *stack);
int					ft_intsize_check(char *str);
int					ft_stack_is_sorted(t_node *stack);
t_node				*ft_create_node(int num, int index);
void				ft_add_node_back(t_node **stack, t_node *new_node);
t_node				*ft_get_last_node(t_node *head);
int					ft_stack_len(t_node *head);
void				ft_free_stack(t_node **stack);
void				ft_update_index(t_node **stack);
int					ft_find_min_num(t_node *stack);
int					ft_find_third_largest_num(t_node *stack);
t_node				ft_find_max_node(t_node *stack);
void				ft_sort_two(t_node **stack_a);
void				ft_sort_three(t_node **stack_a);
void				ft_sort_complex(t_node **stack_a, t_node **stack_b);
void				ft_sort(t_node **stack_a, t_node **stack_b);
void				ft_swap(t_node **stack, char stack_name);
void				ft_push(t_node **src, t_node **dest, char stack_name);
void				ft_rotate(t_node **stack, char stack_name);
void				ft_reverse_rotate(t_node **stack, char stack_name);
void				ft_push_to_stack_b(t_node **stack_a, t_node **stack_b,
						t_node node_to_move, int margin);
void				ft_fill_stack_b(t_node **stack_a, t_node **stack_b,
						int ratio, int ceiling);
t_node				ft_find_first_node_up_to_ceiling(t_node *stack,
						int ceiling);
t_node				ft_find_second_node_up_to_ceiling(t_node *stack,
						int ceiling);
t_node				ft_get_optimal_node(t_node *stack, int ceiling);
void				ft_push_max_node(t_node **stack_a, t_node **stack_b,
						t_node max_node);
void				ft_push_to_stack_a(t_node **stack_a, t_node **stack_b);
void				ft_sort_stack_a(t_node **stack_a, t_node *last_node);
void				ft_refill_stack_a(t_node **stack_a, t_node **stack_b);
int					ft_get_steps_to_head(t_node *stack, t_node node);
#endif