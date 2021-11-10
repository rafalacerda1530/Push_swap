/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:29:40 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/09 23:27:03 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_position(t_stack **st_b, int num)
{
	t_stack	*aux;
	int		cont;

	aux = *st_b;
	cont = 0;
	while (aux)
	{
		cont++;
		if (aux->num == num)
			return (num);
		aux = aux->next;
	}
	return (0);
}

void	find_min(t_stack **st_a, t_swap *swap, int c_big)
{
	t_stack	*aux;

	aux = *st_a;
	swap->first_position = 0;
	while (aux)
	{
		if (aux->num < c_big)
		{
			swap->hold_first = aux->num;
			break ;
		}
		swap->first_position++;
		aux = aux->next;
	}
}

int	check_send(t_stack **st_b, int big, t_swap *swap)
{
	t_stack	*aux;
	int		tmp;

	swap->num = 0;
	if (swap->size_b == 0)
		return (0);
	aux = *st_b;
	tmp = -2147483647;
	while (aux != NULL)
	{
		if (aux->num < big && aux->num > tmp)
			tmp = aux->num;
		aux = aux->next;
	}
	aux = *st_b;
	while (aux)
	{
		swap->num++;
		if (aux->num == tmp)
			check_suport(st_b, swap, swap->num, tmp);
		aux = aux->next;
	}
	return (0);
}

void	put_back_a(t_stack **st_a, t_stack **st_b, t_swap *swap)
{
	t_stack	*aux;
	int		max;
	int		cont;

	max = get_max(st_b);
	aux = *st_b;
	cont = get_position(st_b, max);
	while (aux)
	{
		if (swap->size_b == 3)
			break ;
		if (aux->num == max)
		{
			swap_pa(st_a, st_b, swap);
			aux = *st_b;
			max = get_max(st_b);
			cont = get_position(st_b, max);
		}
		else
		{
			checking(st_b, swap, cont);
			aux = *st_b;
		}
	}
	swap_pa(st_a, st_b, swap);
}
