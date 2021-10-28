/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:56:54 by rarodrig          #+#    #+#             */
/*   Updated: 2021/10/27 22:01:09 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_three(t_stack **st_a, t_swap *swap)
{
    int max;
    int min;
    t_stack *aux;

    max = -2147483648;
    aux = *st_a;
    min = aux->num;
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
        swap_rra(st_a);
        aux = *st_a;
        if (aux->num > aux->next->num)
            swap_sa(st_a, swap);
    }
    if (aux->num == max)
    {
        swap_ra(st_a);
        aux = *st_a;
        if (aux->num > aux->next->num)
            swap_sa(st_a, swap);
    }

}

int sort_small(t_stack **st_a, t_stack **st_b, t_swap *swap)
{
    if (swap->size_a <= 3)
        sort_three(st_a, swap);
    (*st_b)->num = 0;
     return 1;
}
