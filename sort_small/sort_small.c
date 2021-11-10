/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:56:54 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/09 23:38:17 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_condition(t_stack **st_a, t_swap *swap)
{
	swap_ra(st_a, swap);
	if ((*st_a)->num > (*st_a)->next->num)
		swap_sa(st_a, swap);
}

void	sort_three(t_stack **st_a, t_swap *swap)
{
	int		max;
	t_stack	*aux;

	max = -2147483648;
	aux = *st_a;
	while (aux != NULL)
	{
		if (aux->num > max)
			max = aux->num;
		aux = aux->next;
	}
	aux = *st_a;
	if (aux->next->next->num == max)
		if (aux->num > aux->next->num)
			swap_sa(st_a, swap);
	if (aux->next->num == max)
	{
		swap_rra(st_a, swap);
		aux = *st_a;
		if (aux->num > aux->next->num)
			swap_sa(st_a, swap);
	}
	if (aux->num == max)
		sort_condition(st_a, swap);
}

void	s_four(t_stack **st_a, t_stack **st_b, t_swap *swap)
{
	int		min;
	t_stack	*aux;

	aux = *st_a;
	min = get_min(st_a);
	if (aux->num == min)
	{
		swap_pb(st_b, st_a, swap);
		sort_three(st_a, swap);
		swap->first_a = 0;
		swap_pa(st_a, st_b, swap);
		return ;
	}
	else if (aux->next->num == min)
	{
		swap_sa(st_a, swap);
		swap_pb(st_b, st_a, swap);
		sort_three(st_a, swap);
		swap_pa(st_a, st_b, swap);
		return ;
	}
	else
		locate_min(st_a, st_b, swap, min);
}

void	sort_five(t_stack **st_a, t_stack **st_b, t_swap *swap)
{
	t_stack	*aux;

	aux = *st_a;
	swap->i = get_min(st_a);
	swap->max = get_max(st_a);
	while (++swap->index != 2)
	{
		aux = *st_a;
		if (aux->num == swap->i || aux->num == swap->max)
			swap_pb(st_b, st_a, swap);
		else if (aux->next->num == swap->i || aux->next->num == swap->max)
		{
			swap_sa(st_a, swap);
			swap_pb(st_b, st_a, swap);
		}
		else
			locate_five(st_a, st_b, swap, swap->i);
	}
	sort_three(st_a, swap);
	swap->first_a = 0;
	if ((*st_b)->num > (*st_b)->next->num)
		swap_sb(st_b, swap);
	swap_pa(st_a, st_b, swap);
	swap_pa(st_a, st_b, swap);
	swap_ra(st_a, swap);
}

int	sort_small(t_stack **st_a, t_stack **st_b, t_swap *swap)
{
	swap->index = -1;
	swap->first_a = 0;
	(*st_b)->num = 0;
	if (swap->size_a == 2)
		sort_two(st_a, swap);
	if (swap->size_a == 3)
		sort_three(st_a, swap);
	if (swap->size_a == 4)
		s_four(st_a, st_b, swap);
	if (swap->size_a == 5)
		sort_five(st_a, st_b, swap);
	return (1);
}
