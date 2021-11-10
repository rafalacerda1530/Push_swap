/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:37:40 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/09 23:29:20 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	disp_erro(void)
{
	write(1, "Error", 5);
	exit(0);
}

void	free_small(t_stack **stack_a, t_stack **stack_b)
{	
	t_stack	*tmp;

	free(*stack_b);
	while ((*stack_a)->next)
	{
		tmp = (*stack_a)->next;
		free(*stack_a);
		(*stack_a) = tmp;
	}
	free(*stack_a);
}

void	first_swap(t_stack **stack_b, t_stack **stack_a, t_swap *swap)
{
	swap_stacks_f(stack_b, stack_a, swap);
	swap->size_a--;
	swap->first_b = 0;
	swap->size_b++;
	write(1, "pb\n", 3);
	return ;
}
