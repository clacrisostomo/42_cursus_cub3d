/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 22:22:41 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/20 01:51:44 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Locates first occurrence of string litlle into big.
** Size-bounded (len)
** RETURN: If little is empty, return is big
** If little doesn't occur, return NULL
** Else returns pointer to the first character of little
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;
	size_t	lenl;

	b = 0;
	l = 0;
	lenl = ft_strlen(little);
	if (lenl == 0)
		return ((char *)big);
	while (big[b] != '\0' && len-- >= lenl)
	{
		if (big[b] == little[l]
			&& ft_strncmp(((char *)big + b), little, lenl) == 0)
			return ((char *)big + b);
		b++;
	}
	return (NULL);
}
