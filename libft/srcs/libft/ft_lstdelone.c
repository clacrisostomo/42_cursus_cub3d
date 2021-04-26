/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 01:37:48 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/25 12:22:13 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Takes as a parameter an element and frees the
** memory of the element’s content using the function
** del given as a parameter and free the element.
** The memory of next must not be freed.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
