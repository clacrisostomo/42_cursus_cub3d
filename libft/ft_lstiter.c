/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 01:49:28 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/25 01:50:17 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates the list and applies function to each
** element content.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst && f)
	{
		while (lst)
		{
			temp = lst;
			f(lst->content);
			lst = temp->next;
		}
	}
}
