/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 04:20:59 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/25 12:55:15 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates memory for an array of nmeb elements of size bytes
*/

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	size_t	len;
	void	*rec;

	len = nmeb * size;
	rec = malloc(len);
	if (!rec)
		return (0);
	ft_memset(rec, 0, len);
	return (rec);
}
