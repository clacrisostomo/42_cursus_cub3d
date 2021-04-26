/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:51:58 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/20 20:22:54 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copies memory area.
** Library string.h
** Copies no more than n bytes from memory area src to memory area dest
** stopping when character c is found.
** If the areas overlap, result is undefined.
** Retuns a pointer to the next character in dest after c, or NULL if c was not
** found in the first n characters of src.
*/

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		if ((unsigned char)c == ((unsigned char *)src)[i])
			return (dest + i + 1);
		i++;
	}
	return (0);
}
