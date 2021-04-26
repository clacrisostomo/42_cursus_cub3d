/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:35:08 by csantos-          #+#    #+#             */
/*   Updated: 2021/02/25 12:42:08 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates the list applying the function f, then creates
** a nre list with the results and deletes and frees the space
** of the previous one
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	if (!lst)
		return (0);
	result = 0;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, temp);
		lst = lst->next;
	}
	return (result);
}
