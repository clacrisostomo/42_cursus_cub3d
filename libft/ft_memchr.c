/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:32:57 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/20 21:20:09 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Library string
** Scans the initial n bytes of the memory pointed to by s for
** the first instance of c. c and s are unsigned chars
** returns a pointer to the matching byte or NULL if c does not occur.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
