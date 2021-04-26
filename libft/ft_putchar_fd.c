/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 02:29:42 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/20 22:00:50 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the character c to the given file
** descriptor.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
