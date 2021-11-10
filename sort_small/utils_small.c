/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:15:03 by rarodrig          #+#    #+#             */
/*   Updated: 2021/11/09 21:35:38 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **st_a, t_swap *swap)
{
	if ((*st_a)->next->num < (*st_a)->num)
		swap_sa(st_a, swap);
	else
		return ;
}
