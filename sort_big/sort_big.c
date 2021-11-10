/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:53:24 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/09 22:43:17 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_number(t_stack **stack, int c_big, t_swap *swap)
{
	t_stack	*aux;
	int		num;

	aux = *stack;
	swap->second_position = 0;
	num = 0;
	while (aux)
	{
		if (aux->num <= c_big)
			num = aux->num;
		aux = aux->next;
	}
	aux = *stack;
	while (aux)
	{
		if (aux->num == num)
			return (num);
		aux = aux->next;
		swap->second_position++;
	}
	return (num);
}

int	find_chunk(t_stack **stack, t_swap *swap)
{
	t_stack	*tmp;
	t_stack	*aux;

	swap->num = 2147483647;
	aux = *stack;
	swap->min = get_min(stack);
	while (*stack)
	{
		tmp = *stack;
		while (tmp)
		{
			if (tmp->num > swap->min && tmp->num < swap->num)
				swap->num = tmp->num;
			tmp = tmp->next;
		}
		swap->cont_chunk++;
		aux = aux->next;
		if (swap->cont_chunk == 25)
			return (swap->num);
		if (aux->next == NULL)
			return (swap->num);
		swap->min = swap->num;
		swap->num = 2147483647;
	}
	return (swap->num);
}

void	check_second(t_stack **st_a, t_stack **st_b, t_swap *swap)
{
	t_stack	*aux;

	aux = *st_a;
	if (swap->second_position == 0)
	{
		check_send(st_b, swap->hold_second, swap);
		swap_pb(st_b, st_a, swap);
		return ;
	}
	while (aux)
	{
		if (swap->size_a == 1)
			return ;
		aux = aux->next;
		aux = *st_a;
		if (aux->num == swap->hold_second)
		{
			check_send(st_b, swap->hold_second, swap);
			swap_pb(st_b, st_a, swap);
			return ;
		}
		swap_rra(st_a, swap);
	}
}

void	check_swap(t_stack **st_a, t_stack **st_b, t_swap *swap, int c_big)
{
	int		middle;

	middle = swap->size_a / 2;
	swap->hold_second = get_number(st_a, c_big, swap);
	find_min(st_a, swap, c_big);
	if (swap->first_position <= middle - (swap->second_position - middle))
		check_to_send(st_a, st_b, swap);
	else
		check_second(st_a, st_b, swap);
	return ;
}

void	sort_big(t_stack **st_a, t_stack **st_b, t_swap *swap, int count)
{
	t_stack	*aux;
	int		c_big;

	aux = *st_a;
	c_big = find_chunk(st_a, swap);
	while (swap->size_a > 0)
	{
		if (swap->size_a == 1)
		{
			check_send(st_b, (*st_a)->num, swap);
			swap_pb(st_b, st_a, swap);
			break ;
		}
		if (count == swap->cont_chunk)
		{
			swap->cont_chunk = 0;
			c_big = find_chunk(st_a, swap);
			count = 0;
		}
		check_swap(st_a, st_b, swap, c_big);
		count++;
	}
	*st_a = new_node();
	put_back_a(st_a, st_b, swap);
}
