/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 02:33:20 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/20 22:01:09 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the string s to the given file
** descriptor, followed by a newline.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
