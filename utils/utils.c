/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:58:08 by rarodrig          #+#    #+#             */
/*   Updated: 2021/10/24 20:25:58 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_first(t_stack **stack)
{
	t_stack *tmp;
    t_stack *aux;

    tmp = new_node();
    aux = new_node();

    aux = *stack;
    tmp->num = aux->num;
    aux->num = aux->next->num;
    aux->next->num = tmp->num;
}

void swap_stacks_f(t_stack **s_dst, t_stack **s_src)
{
	t_stack *aux;
    t_stack *tmp;

	tmp = *s_dst;
    aux = new_node();
	tmp->num = (*s_src)->num;
	dell_first(s_src);
	return;

}