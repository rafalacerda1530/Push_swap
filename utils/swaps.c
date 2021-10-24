/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:59:42 by rarodrig          #+#    #+#             */
/*   Updated: 2021/10/24 20:34:01 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap_sa_sb(t_stack **stack, t_swap *swap)
{
    if (swap->size_a <= 1 || swap->size_b <= 1)
        return;
    t_stack *tmp;
    t_stack *aux;
    tmp = new_node();
    aux = new_node();

    aux = *stack;
    tmp->num = aux->num;
    aux->num = aux->next->num;
    aux->next->num = tmp->num;
}

void swap_ss(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
    if (swap->size_a <= 1 || swap->size_b <= 1)
        return;

    swap_first(stack_a);
    swap_first(stack_b);
}

void swap_pa(t_stack **stack_a, t_stack **stack_b, t_swap *swap)
{
    t_stack *aux;
    t_stack *tmp;

    if (swap->size_b == 0)
        return;
    tmp = *stack_a;
    aux = new_node();
    if (swap->first_a)
    {
        swap_stacks_f(stack_a, stack_b);
        swap->size_b--;
	    swap->first_a = 0;
        free(aux);
       return;
    }
    else
    {
        aux->num = (*stack_b)->num;
        aux->next = tmp;
        *stack_a = aux;
        dell_first(stack_b);
        swap->size_b--;
        swap->size_a++;
    }
}

void swap_pb(t_stack **stack_b, t_stack **stack_a, t_swap *swap)
{
    t_stack *aux;
    t_stack *tmp;

    if (swap->size_a == 0)
       return;
    tmp = *stack_b;
    aux = new_node();
    if (swap->first_b)
    {
        swap_stacks_f(stack_b, stack_a);
        swap->size_a--;
	    swap->first_b = 0;
        free(aux);
       return;
    }
    else
    {
        aux->num = (*stack_a)->num;
        aux->next = tmp;
        *stack_b = aux;
        dell_first(stack_a);
        swap->size_b++;
        swap->size_a--;
    }
}

void	dell_first(t_stack **stack)
{
    t_stack *aux;
	t_stack *tmp;

    aux = *stack;
	tmp = (*stack)->next;
	free(aux);
 	*stack = tmp;
}
