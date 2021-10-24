/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 22:51:27 by rarodrig          #+#    #+#             */
/*   Updated: 2021/05/22 22:51:27 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == '-' )
			i++;
		if (c[i] >= '0' && c[i] <= '9')
		{
			return (1);
		}
		else
			return (0);
		i++;
	}
	return (0);
}
