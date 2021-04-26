/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:10:54 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/20 22:29:01 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Compare memory areas
** Library: string
** compares the first n bytes (interpreted as unsigned char)
** of the memory of s1 and s2
** return an integer less than, equal to or greater than 0
** for a non zero, the sign is determined by the sign of the diff
** between the first pair of bytes that differ in s1 and s2
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
