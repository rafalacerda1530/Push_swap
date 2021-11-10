/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:59:18 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/09 23:28:20 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_to_send(t_stack **st_a, t_stack **st_b, t_swap *swap)
{
	t_stack	*aux;

	aux = *st_a;
	if (swap->first_position == 0)
	{
		check_send(st_b, swap->hold_first, swap);
		swap_pb(st_b, st_a, swap);
		return ;
	}
	while (aux)
	{
		aux = *st_a;
		if (aux->num == swap->hold_first)
		{
			check_send(st_b, swap->hold_first, swap);
			swap_pb(st_b, st_a, swap);
			return ;
		}
		swap_ra(st_a, swap);
	}
}

void	checking(t_stack **st_b, t_swap *swap, int cont)
{
	if (cont > (swap->size_b / 2))
		swap_rrb(st_b, swap);
	else
		swap_rb(st_b, swap);
}

int	check_suport(t_stack **st_b, t_swap *swap, int cont, int tmp)
{
	t_stack	*aux;

	aux = *st_b;
	if (cont > (swap->size_b / 2))
	{
		while (aux->num != tmp)
		{
			swap_rrb(st_b, swap);
			aux = *st_b;
		}
		return (1);
	}
	else
	{
		while (aux->num != tmp)
		{
			swap_rb(st_b, swap);
			aux = *st_b;
		}
		return (1);
	}
}
