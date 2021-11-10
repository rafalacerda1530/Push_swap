/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:59:42 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/09 19:48:36 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_sb(t_stack **stack, t_swap *swap)
{
	t_stack	*tmp;
	t_stack	*aux;

	if (swap->size_b <= 1)
		return ;
	tmp = new_node();
	aux = *stack;
	tmp->num = aux->num;
	aux->num = aux->next->num;
	aux->next->num = tmp->num;
	swap->mov++;
	free(tmp);
	write(1, "sb\n", 3);
}

void	swap_sa(t_stack **stack, t_swap *swap)
{
	t_stack	*tmp;
	t_stack	*aux;

	if (swap->size_a <= 1)
		return ;
	tmp = new_node();
	aux = *stack;
	tmp->num = aux->num;
	aux->num = aux->next->num;
	aux->next->num = tmp->num;
	swap->mov++;
	free(tmp);
	write(1, "sa\n", 3);
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	if (swap->size_a <= 1 || swap->size_b <= 1)
		return ;
	swap_first(stack_a, swap);
	swap_first(stack_b, swap);
	write(1, "ss\n", 3);
}

void	swap_pa(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
	t_stack	*aux;
	t_stack	*tmp;

	if (swap->size_b == 0)
		return ;
	tmp = *stack_a;
	if (swap->first_a)
	{
		tmp->num = (*stack_b)->num;
		dell_first(stack_b);
		swap->first_a = 0;
		write(1, "pa\n", 3);
		return ;
	}
	aux = new_node();
	aux->num = (*stack_b)->num;
	aux->next = tmp;
	*stack_a = aux;
	dell_first(stack_b);
	swap->size_b--;
	swap->size_a++;
	swap->mov++;
	write(1, "pa\n", 3);
}

void	swap_pb(t_stack **stack_b, t_stack **stack_a, t_swap *swap)
{
	t_stack	*aux;
	t_stack	*tmp;

	if (swap->size_a == 0)
		return ;
	tmp = *stack_b;
	aux = new_node();
	if (swap->first_b)
	{
		first_swap(stack_b, stack_a, swap);
		free(aux);
		return ;
	}
	else
	{
		aux->num = (*stack_a)->num;
		aux->next = tmp;
		*stack_b = aux;
		dell_first(stack_a);
		swap->size_b++;
		swap->size_a--;
		swap->mov++;
	}
	write(1, "pb\n", 3);
}
