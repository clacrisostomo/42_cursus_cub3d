/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 00:08:24 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/25 12:54:15 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Converts a char into an integer
*/

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *c)
{
	int	sign;
	int	i;
	int	nbr;
	int	conv;

	sign = 1;
	i = 0;
	nbr = 0;
	conv = 0;
	while (ft_isspace(c[i]) == 1)
		i++;
	if (c[i] == '+' || c[i] == '-')
	{
		if (c[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(c[i]) == 1)
	{
		nbr = (c[i] - '0');
		conv = (conv * 10) + nbr;
		i++;
	}
	return (conv * sign);
}
