/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:16:41 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/19 18:55:21 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Library <bsd/string.h>
** Size-bounded string copying.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t sizedest)
{
	size_t	sizesrc;
	size_t	i;

	sizesrc = ft_strlen(src);
	i = 0;
	if (!src || !dest)
		return (0);
	if (sizedest != 0)
	{
		while (src[i] != '\0' && i < (sizedest - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (sizesrc);
}
