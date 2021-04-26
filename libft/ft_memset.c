/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 01:41:32 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/20 02:49:11 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Fills memory with a constant byte
** Library: <string.h>
** Fills the first n bytes of memory area pointed to by s
** with the constant byte c.
** Returns a pointer to the memory area s.
** c is an unsigned char
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
