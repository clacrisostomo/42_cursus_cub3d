/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:45:35 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/21 00:05:33 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copy memory area
** Library string
**Copies n bytes from memory src to dest. Copies to a temp array
** before copies to dest.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n != 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	else
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
