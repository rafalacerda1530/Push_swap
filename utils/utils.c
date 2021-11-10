/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:58:08 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/09 01:08:02 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_first(t_stack **stack, t_swap *swap)
{
	t_stack	*tmp;
	t_stack	*aux;

	tmp = new_node();
	aux = new_node();
	aux = *stack;
	tmp->num = aux->num;
	aux->num = aux->next->num;
	aux->next->num = tmp->num;
	swap->mov++;
}

void	swap_stacks_f(t_stack **s_dst, t_stack **s_src, t_swap *swap)
{
	t_stack	*aux;
	t_stack	*tmp;

	tmp = *s_dst;
	aux = new_node();
	tmp->num = (*s_src)->num;
	dell_first(s_src);
	swap->mov++;
	free(aux);
	return ;
}

void	rotate(t_stack **stack, t_swap *swap)
{
	t_stack	*aux;
	t_stack	*last;
	t_stack	*tmp;

	aux = (*stack)->next;
	tmp = aux;
	last = *stack;
	last->next = NULL;
	while (aux->next)
		aux = aux->next;
	aux->next = last;
	*stack = tmp;
	swap->mov++;
}

void	rotate_r(t_stack **stack, t_swap *swap)
{
	t_stack	*aux;
	t_stack	*last;
	t_stack	*tmp;

	aux = *stack;
	tmp = aux;
	while (aux->next->next)
		aux = aux->next;
	last = aux->next;
	aux->next = NULL;
	last->next = NULL;
	last->next = tmp;
	*stack = last;
	swap->mov++;
}

void	swap_rrr(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	swap_rra(stack_a, swap);
	swap_rrb(stack_b, swap);
}
