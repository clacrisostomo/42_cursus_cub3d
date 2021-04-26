/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:41:43 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/09 01:52:17 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Library <ctype.h>
** convert lowercase to uppercase
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}
