/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 01:13:00 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/22 02:31:10 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Locates character in string.
** Returns a pointer to the first occurrence of c in s.
** Returns NULL if the character is not found.
** If c is specified as '\0', it returns a pointer to the terminator.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while ((s[i] != '\0') && ((char)c != s[i]))
		i++;
	if ((char)c == s[i])
		return ((char *)s + i);
	else
		return (0);
}
