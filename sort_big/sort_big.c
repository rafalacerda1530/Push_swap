/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:53:24 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/05 23:32:51 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int get_number(t_stack **stack, int c_big, t_swap *swap)
{
    t_stack *aux;
    aux = *stack;
    int num;

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
            return(num);
        aux = aux->next;
        swap->second_position++;
    }
    return(num);
}

int find_chunk(t_stack **stack, t_swap *swap)
{
    int num;
    int min;
    t_stack *tmp;
    t_stack *aux;

    num = 2147483647;
    aux = *stack;
    min = get_min(stack);
    while (aux)
    {
        tmp = *stack;
        while (tmp)
        {
            if (tmp->num > min && tmp->num < num)
                num = tmp->num;
            tmp = tmp->next;
        }
        swap->cont_chunk++;
        aux = aux->next;
        if (swap->cont_chunk == 19)
            return (num);
        if (aux->next == NULL)
            return(num);
        min = num;
        num = 2147483647;
    }
    return(num);
}

void check_second(t_stack **st_a, t_stack **st_b, t_swap *swap)
{
    t_stack *aux;
    aux = *st_a;

    if (swap->second_position == 0)
    {
        check_send(st_b, swap->hold_second, swap);
        swap_pb(st_b, st_a, swap);
        return;
    }
    while (aux)
    {
        if (swap->size_a == 1)
            return;
        aux = aux->next;
        aux = *st_a;
        if (aux->num == swap->hold_second)
        {
            check_send(st_b, swap->hold_second, swap);
            swap_pb(st_b, st_a, swap);
            return;
        }
        swap_rra(st_a, swap);
    }
}

void check_swap(t_stack **st_a, t_stack **st_b, t_swap *swap, int c_big)
{
    t_stack *aux;
    int middle;

    middle = swap->size_a / 2;
    aux = *st_a;
    swap->hold_second = get_number(st_a, c_big, swap);
    find_min(st_a, swap, c_big);
    if (swap->first_position <= (swap->second_position - middle))
    {
        if (swap->first_position == 0)
        {
            check_send(st_b, swap->hold_first, swap);
            swap_pb(st_b, st_a, swap);
            return;
        }
        while (aux)
        {
            aux = *st_a;
            if (aux->num == swap->hold_first)
            {
                check_send(st_b, swap->hold_first, swap);
                swap_pb(st_b, st_a, swap);
                return;
            }
            swap_ra(st_a, swap);
        }
    }
    else
        check_second(st_a, st_b, swap);
}

void sort_big(t_stack **st_a, t_stack **st_b, t_swap *swap)
{
    t_stack *aux;
    int c_big;
    int count;

    aux = *st_a;
    count = 0;
    (*st_b)->num = 0;
    c_big = find_chunk(st_a, swap);

    while (swap->size_a > 0)
   {
        if (swap->size_a == 1)
        {
            check_send(st_b, (*st_a)->num, swap);
            swap_pb(st_b, st_a, swap);
            break;
        }
        if (count > swap->cont_chunk)
            c_big = find_chunk(st_a, swap);
        count++;
        check_swap(st_a, st_b, swap, c_big);
   }
   *st_a = new_node();
   put_back_a(st_a, st_b, swap);
}
