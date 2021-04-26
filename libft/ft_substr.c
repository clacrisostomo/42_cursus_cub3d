/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 03:26:43 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/22 21:37:13 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	sizestr;

	sizestr = ft_strlen(s);
	if (!s)
		return (0);
	if (start > sizestr)
		return (ft_strdup(""));
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (0);
	ft_strlcpy(subs, (s + start), len + 1);
	subs[len] = '\0';
	return (subs);
}
