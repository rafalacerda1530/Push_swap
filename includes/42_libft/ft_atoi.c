/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:45:41 by rarodrig          #+#    #+#             */
/*   Updated: 2021/05/22 20:45:41 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ignore(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	number;

	sign = 1;
	number = 0;
	while (ft_ignore(*nptr) == 1)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign *= -1;
	while (ft_isdigit((char *)nptr) == 1)
		number = number * 10 + (*nptr++ - '0');
	if ((number * sign) > INT_MAX || (number * sign) < INT_MIN)
	{
		write(1, "Error", 5);
		exit(0);
	}
	return (number * sign);
}
