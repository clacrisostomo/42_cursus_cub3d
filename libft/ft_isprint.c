/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:36:31 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/09 01:34:09 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Library <ctype.h>
** Checks if character is printable including space
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
