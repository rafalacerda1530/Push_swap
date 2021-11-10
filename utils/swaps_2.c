/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:34:26 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/09 19:29:52 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_ra(t_stack **stack, t_swap *swap)
{
	rotate(stack, swap);
	write (1, "ra\n", 3);
}

void	swap_rb(t_stack **stack, t_swap *swap)
{
	rotate(stack, swap);
	write (1, "rb\n", 3);
}

void	swap_rr(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	swap_ra(stack_a, swap);
	swap_rb(stack_b, swap);
	write (1, "rr\n", 3);
}

void	swap_rra(t_stack **stack_a, t_swap *swap)
{
	rotate_r(stack_a, swap);
	write (1, "rra\n", 4);
}

void	swap_rrb(t_stack **stack_b, t_swap *swap)
{
	rotate_r(stack_b, swap);
	write (1, "rrb\n", 4);
}
