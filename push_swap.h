/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:07:56 by rarodrig          #+#    #+#             */
/*   Updated: 2021/10/24 20:44:17 by rarodrig         ###   ########.fr       */
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

void swap_sa_sb(t_stack **stack, t_swap *swap);
void swap_pb(t_stack **stack_b, t_stack **stack_a, t_swap *swap);
void swap_pa(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
void swap_ss(t_stack **stack_a, t_stack **stack_b, t_swap *swap);
void swap_first(t_stack **stack);
void	dell_first(t_stack **stack);
void swap_stacks_f(t_stack **s_dst, t_stack **s_src);
t_stack *new_node (void);

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