/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 22:39:48 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/09 21:37:44 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	locate_min(t_stack **st_a, t_stack **st_b, t_swap *swap, int min)
{
	t_stack	*aux;

	aux = *st_a;
	while (aux)
	{
		aux = *st_a;
		if (aux->num == min)
		{
			swap_pb(st_b, st_a, swap);
			sort_three(st_a, swap);
			swap_pa(st_a, st_b, swap);
			return ;
		}
		swap_rra(st_a, swap);
	}
}

void	locate_five(t_stack **st_a, t_stack **st_b, t_swap *swap, int min)
{
	t_stack	*aux;

	aux = *st_a;
	while (aux)
	{
		aux = *st_a;
		if (aux->num == min || aux->num == swap->max)
		{
			swap_pb(st_b, st_a, swap);
			return ;
		}
		swap_rra(st_a, swap);
	}
}

int	get_min(t_stack **stack)
{
	t_stack	*aux;
	int		min;

	aux = *stack;
	min = aux->num;
	while (aux != NULL)
	{
		if (aux->num < min)
			min = aux->num;
		aux = aux->next;
	}
	return (min);
}

int	get_max(t_stack **stack)
{
	t_stack	*aux;
	int		max;

	aux = *stack;
	max = aux->num;
	while (aux != NULL)
	{
		if (aux->num > max)
			max = aux->num;
		aux = aux->next;
	}
	return (max);
}
