/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 01:23:13 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/22 02:31:03 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Locates the last occurrence of c in the string s.
** Returns a pointer to the last occurrence of c in s.
** Returns NULL if the character is not found.
** If c is specified as '\0', it returns a pointer to the terminator.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i != 0 && (char)c != s[i])
		i--;
	if ((char)c == s[i])
		return ((char *)s + i);
	else
		return (0);
}
