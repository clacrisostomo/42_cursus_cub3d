/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:18:32 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/25 01:22:56 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Creates a new element and puts it into the beginning
** of the list
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}
