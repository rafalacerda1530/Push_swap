/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:19:18 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/09 22:43:37 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*new_node(void)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->next = NULL;
	new_node->num = 0;
	return (new_node);
}

void	dell_first(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*tmp;

	aux = *stack;
	tmp = (*stack)->next;
	free(aux);
	*stack = tmp;
}

void	initialize_list(t_swap *swap)
{
	swap->first_position = 0;
	swap->second_position = 0;
	swap->cont_chunk = 0;
	swap->size_a = 0;
	swap->mov = 0;
	swap->size_b = 1;
	swap->first_a = 1;
	swap->max = 0;
	swap->hold_second = 0;
	swap->first_b = 1;
	swap->size_split = 0;
	swap->stack_a = new_node();
	swap->stack_b = new_node();
	swap->i = 1;
	swap->check = 1;
	swap->index = -1;
	swap->min = 0;
	swap->num = 0;
}

int	check_sort(t_stack **stack_a)
{
	t_stack	*aux;
	int		curr;

	aux = *stack_a;
	curr = 0;
	while (aux->next != NULL)
	{
		curr = aux->num;
		aux = aux->next;
		if (curr > aux->num)
			return (1);
	}
	return (0);
}
