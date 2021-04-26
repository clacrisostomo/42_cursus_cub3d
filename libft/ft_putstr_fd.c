/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 02:31:31 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/20 22:02:43 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the string s to the given file
** descriptor.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	pos;

	pos = 0;
	while (s[pos] != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	return ;
}
