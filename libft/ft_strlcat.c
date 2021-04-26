/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:15:17 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/17 15:16:30 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Library: <bsd/string.h>
** Size-bounded string concatenation.
*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t sizedest)
{
	size_t	i;
	size_t	j;

	if (sizedest <= ft_strlen(dest))
		return (sizedest + ft_strlen(src));
	i = ft_strlen(dest);
	j = 0;
	while ((src[j] != '\0') && ((i + 1) < sizedest))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[j]));
}
