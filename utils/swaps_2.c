/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:34:26 by rarodrig          #+#    #+#             */
/*   Updated: 2021/10/27 18:54:43 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_ra(t_stack **stack)
{
    rotate(stack);
    write(1, "ra\n",3);
}

void swap_rb(t_stack **stack)
{
    rotate(stack);
    write(1, "rb\n",3);
}

void swap_rr(t_stack **stack_a,t_stack **stack_b)
{
    swap_ra(stack_a);
    swap_rb(stack_b);
    write(1, "rr\n",3);
}

void swap_rra(t_stack **stack_a)
{
    rotate_r(stack_a);
    write(1, "rra\n",4);
}

void swap_rrb(t_stack **stack_b)
{
    rotate_r(stack_b);
    write(1, "rrb\n",4);
}
