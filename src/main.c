/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:48:38 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/10 12:27:21 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
		free(split[i++]);
	if (split)
		free(split);
}

int	count_argv(char **argv)
{
	char	**splitted;
	int		i;
	int		index;
	int		size_split;

	i = 1;
	index = 0;
	size_split = 0;
	while (argv[i] != NULL)
	{
		splitted = ft_split(argv[i], ' ');
		while (splitted[index])
		{
			size_split++;
			index++;
		}
		index = 0;
		free_split(splitted);
		*splitted = NULL;
		i++;
	}
	return (size_split);
}

int	check_double(t_stack *stack_a, int position)
{
	t_stack	*curr;
	t_swap	swap;

	if (swap.first_a == 1 && position == 0)
	{
		swap.first_a = 0;
		return (1);
	}
	curr = stack_a;
	while (curr->next)
	{
		if (curr->num == position)
		{
			write(1, "Error", 5);
			exit (0);
		}
		curr = curr->next;
	}
	return (1);
}

int	initialize_stack(t_stack **stack, char **argv, t_swap *swap)
{
	t_stack	*aux;
	char	**splitted;

	aux = *stack;
	swap->size_split = count_argv(argv);
	while (argv[swap->i] != NULL)
	{
		splitted = ft_split(argv[swap->i], ' ');
		while (splitted[++swap->index])
		{
			if (!ft_isdigit(splitted[swap->index]))
				disp_erro();
			check_double(*stack, ft_atoi((char *) *splitted));
			aux->num = ft_atoi((char *) *splitted);
			if (swap->check >= swap->size_split)
				break ;
			aux->next = new_node();
			aux = aux->next;
			swap->check++;
		}
		swap->index = -1;
		free_split(splitted);
		swap->i++;
	}
	return (swap->size_split);
}

int	main(int argc, char **argv)
{
	t_swap	swap;
	int		cont;

	cont = 0;
	if (argc - 1 == 1)
		return (0);
	initialize_list(&swap);
	swap.size_a = initialize_stack(&swap.stack_a, argv, &swap);
	if (!check_sort(&swap.stack_a))
		exit(0);
	if (argc - 1 <= 5)
		sort_small(&swap.stack_a, &swap.stack_b, &swap);
	else
		sort_big(&swap.stack_a, &swap.stack_b, &swap, cont);
	if (argc - 1 == 3 || argc - 1 == 4 || argc - 1 == 5)
		free_small(&swap.stack_a, &swap.stack_b);
	else if (argc - 1 == 2)
	{
		free(swap.stack_a->next);
		free(swap.stack_b);
	}
	if (argc - 1 > 5)
		free_small(&swap.stack_a, &swap.stack_b);
	return (0);
}
