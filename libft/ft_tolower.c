/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:46:13 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/12 01:09:21 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Library <ctype.h>
** Converts uppercase to lowercase
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
