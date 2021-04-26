/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:35:39 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/24 16:01:26 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lettercount(const char *s, char c)
{
	int			lcount;

	lcount = 0;
	while (s[lcount] != c && s[lcount] != '\0')
		++lcount;
	return (lcount);
}

static size_t	wordcount(char const *s, char c)
{
	size_t		lcount;
	size_t		words;
	size_t		flag;
	size_t		start;

	lcount = 0;
	words = 0;
	flag = 0;
	while (s[lcount])
	{
		start = flag;
		if (s[lcount] == c)
			flag = 0;
		else
			flag = 1;
		if (start != flag && start == 1)
			++words;
		++lcount;
	}
	if (flag == 1)
		++words;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t		words;
	char		**receiver;
	int			lcount;

	if (!s)
		return (0);
	words = wordcount(s, c);
	receiver = ft_calloc(words + 1, sizeof(char *));
	if (!receiver)
		return (0);
	lcount = -1;
	words = 0;
	while (s[++lcount])
	{
		if (s[lcount] != c && s[lcount] != '\0')
		{
			receiver[words] = ft_substr(s, lcount, lettercount(&s[lcount], c));
			++words;
			lcount = lcount + lettercount(&s[lcount], c) - 1;
		}
	}
	return (receiver);
}
