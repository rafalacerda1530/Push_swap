/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:48:38 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/06 00:00:54 by rarodrig         ###   ########.fr       */
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
    t_swap  swap;

    if (swap.first_a == 1 && position == 0)
    {
        swap.first_a = 0;
        return 1;
    }
    curr = stack_a;
    while(curr->next)
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
    t_stack *aux;
    char **splitted;
    int size_split;
    int check;
    unsigned int teste;
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
            //AJUSTAR VALOR DE MAX INT
            if ((long int)ft_atoi((char *) *splitted) > INT_MAX)
            {
                write(1, "Error", 5);
                exit(0);
            }
            check_double(*stack, ft_atoi((char *) *splitted));
            aux->num = ft_atoi((char *) *splitted);
            if (check >= size_split)
                break;
            aux->next = new_node();
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
    swap.first_position = 0;
    swap.second_position = 0;
    swap.cont_chunk = 0;
    swap.size_a = 0;
    swap.mov = 0;
    swap.size_b = 1;
    swap.first_a = 1;
    swap.max = 0;
    swap.hold_second = 0;
    swap.first_b = 1;
    swap.stack_a = new_node();
    swap.stack_b = new_node();
    swap.size_a =  initialize_stack(&swap.stack_a, argv);

    if (argc - 1 <= 5)
        sort_small(&swap.stack_a, &swap.stack_b, &swap);
    else
        sort_big(&swap.stack_a, &swap.stack_b, &swap);

    return (1);
}
