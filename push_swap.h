/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:07:56 by rarodrig          #+#    #+#             */
/*   Updated: 2021/10/27 19:55:17 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./includes/42_libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct  s_stack
{
    int num;
    struct s_stack *next;
}   t_stack;

typedef struct  s_swap
{
    t_stack *stack_a;
    t_stack *stack_b;
    int size_a;
    int size_b;
    int first_a;
    int first_b;
}   t_swap;
#endif

void swap_sb(t_stack **stack, t_swap *swap);
void swap_sa(t_stack **stack, t_swap *swap);
void swap_pb(t_stack **stack_b, t_stack **stack_a, t_swap *swap);
void swap_pa(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
void swap_ss(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
void swap_first(t_stack **stack);
void dell_first(t_stack **stack);
void swap_stacks_f(t_stack **s_dst, t_stack **s_src);
void swap_ra(t_stack **stack);
void swap_rb(t_stack **stack);
void swap_rr(t_stack **stack_a,t_stack **stack_b);
void rotate(t_stack **stack);
void rotate_r(t_stack **stack);
void swap_rra(t_stack **stack_a);
void swap_rrb(t_stack **stack_a);
int sort_small(t_stack **st_a, t_stack **st_b, t_swap *swap);
t_stack *new_node (void);
