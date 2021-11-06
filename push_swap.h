/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:07:56 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/05 21:37:10 by rarodrig         ###   ########.fr       */
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
    int max;
    int first_a;
    int first_b;
    int mov;
    int hold_second;
    int hold_first;
    int first_position;
    int second_position;
    int cont_chunk;
    int teste;
}   t_swap;
#endif

void swap_sb(t_stack **stack, t_swap *swap);
void swap_sa(t_stack **stack, t_swap *swap);
void swap_pb(t_stack **stack_b, t_stack **stack_a, t_swap *swap);
void swap_pa(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
void swap_ss(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
void swap_first(t_stack **stack, t_swap *swap);
void dell_first(t_stack **stack);
void swap_stacks_f(t_stack **s_dst, t_stack **s_src, t_swap *swap);
void swap_ra(t_stack **stack, t_swap *swap);
void swap_rb(t_stack **stack, t_swap *swap);
void swap_rr(t_stack **stack_a,t_stack **stack_b, t_swap *swap);
void rotate(t_stack **stack, t_swap *swap);
void rotate_r(t_stack **stack, t_swap *swap);
void swap_rra(t_stack **stack_a, t_swap *swap);
void swap_rrb(t_stack **stack_b, t_swap *swap);
int sort_small(t_stack **st_a, t_stack **st_b, t_swap *swap);
int get_min(t_stack **stack);
int get_max(t_stack **stack);
void locate_min(t_stack **st_a, t_stack **st_b, t_swap *swap, int min);
void sort_three(t_stack **st_a, t_swap *swap);
void sort_five(t_stack **st_a, t_stack **st_b, t_swap *swap);
void locate_five(t_stack **st_a, t_stack **st_b, t_swap *swap, int min);
void sort_big(t_stack **st_a, t_stack **st_b, t_swap *swap);
void find_min(t_stack **st_a, t_swap *swap, int c_big);
int check_send(t_stack **st_b, int big, t_swap *swap);
void put_min(t_stack **st_a, t_stack **st_b, t_swap *swap);
void put_back_a(t_stack **st_a, t_stack **st_b, t_swap *swap);

t_stack *new_node (void);
