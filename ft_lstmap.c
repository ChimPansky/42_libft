/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:48:06 by tkasbari          #+#    #+#             */
/*   Updated: 2023/09/14 17:08:07 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	new_node = ft_lstnew(f(lst->content));
	if (!new_node)
	{
		ft_lstclear(&new_node, del);
		return (NULL);
	}
	new_list = new_node;
	lst = lst->next;
	while (lst)
	{
		new_node->next = ft_lstnew(f(lst->content));
		if (!new_node->next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node = new_node->next;
		lst = lst->next;
	}
	return (new_list);
}
