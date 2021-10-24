/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:48:38 by rarodrig          #+#    #+#             */
/*   Updated: 2021/10/24 20:30:09 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int count_argv(char **argv)
{
    char **splitted;
    int i;
    int size_split;

    i = 1;
    size_split = 0;
    while(argv[i] != NULL)
    {
        splitted = ft_split(argv[i], ' ');
        while(*splitted)
        {
            splitted++;
            size_split++;
        }
        i++;
    }
    return (size_split);
}

t_stack *new_node (void)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    new_node->next = NULL;
    new_node->num = 0;

    return (new_node);
}

int check_double(t_stack *stack_a, int position)
{
    t_stack *curr;

    curr = stack_a;
    while(curr != NULL)
    {
        if (curr->num == position)
        {
            write(1, "Error", 5);
            exit (0);
        }
        curr = curr->next;
    }
    return 1;
}

int initialize_stack(t_stack **stack, char **argv)
{
    t_stack *tmp;
    t_stack *aux;
    char **splitted;
    int size_split;
    int check;
    int i;

    aux = *stack;
    size_split = count_argv(argv);
    check = 1;
    i = 1;
    while(argv[i] != NULL)
    {
        splitted = ft_split(argv[i], ' '); 
        while(*splitted)
        {
            check_double(*stack, ft_atoi((char *) *splitted));
            aux->num = ft_atoi((char *) *splitted);
            if (check >= size_split)
                break;
            tmp =  new_node();
            aux->next = tmp;
            aux = aux->next;
            splitted++;
            check++;
        }
        i++;
    }
    return (size_split);
}

int main (int argc, char **argv)
{
    t_swap swap;

    argc += 0;
    swap.size_a = 1;
    swap.size_b = 1;
    swap.first_a = 1;
    swap.first_b = 1;
    swap.stack_a = new_node();
    swap.stack_b = new_node();
    swap.size_b =  initialize_stack(&swap.stack_b, argv);

    swap_pa(&swap.stack_a, &swap.stack_b, &swap);
    swap_pa(&swap.stack_a, &swap.stack_b, &swap);
    swap_sa_sb(&swap.stack_a, &swap);

    //swap_pb(&swap.stack_b, &swap.stack_a, &swap);
    //swap_pb(&swap.stack_b, &swap.stack_a, &swap);

    swap_ss(&swap.stack_a, &swap.stack_b, &swap);
    while (swap.stack_a)
    {
        printf("stack a = %d\n", swap.stack_a->num);
        swap.stack_a = swap.stack_a->next;
    }
    while (swap.stack_b)
    {
        printf("stack b = %d\n", swap.stack_b->num);
        swap.stack_b = swap.stack_b->next;
    }
    return (1);
}
