/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 02:55:42 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/20 02:58:00 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Erases the data in the n bytes of the memory
** starting at the location pointed by s by writing
** zeros (\0) to that area.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
