/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarkis <msarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:51:03 by msarkis           #+#    #+#             */
/*   Updated: 2024/07/29 08:51:05 by msarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*last_node;
	t_list	*new_node;
	void	*content_result;

	last_node = NULL;
	new_list = NULL;
	new_node = NULL;
	while (lst != NULL)
	{
		content_result = (*f)(lst->content);
		new_node = ft_lstnew(content_result);
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (last_node != NULL)
			last_node->next = new_node;
		else
			new_list = new_node;
		last_node = new_node;
		lst = lst->next;
	}
	return (new_list);
}
