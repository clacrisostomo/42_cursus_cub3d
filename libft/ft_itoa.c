/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 02:16:47 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/25 01:22:08 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Converts integer into char an allocates memory for string
*/

#include "libft.h"

static void	convnbr(int c, char *str, long int i)
{
	unsigned int	nbr;

	nbr = c;
	if (c < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr >= 10)
		convnbr((nbr / 10), str, (i - 1));
	str[i] = (nbr % 10) + '0';
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	j;
	long int	count;

	j = n;
	count = 0;
	if (j <= 0)
		count++;
	while (j)
	{
		j = (j / 10);
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = 0;
	convnbr(n, str, (count - 1));
	return (str);
}
