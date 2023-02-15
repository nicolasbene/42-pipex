/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:47:17 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/25 17:47:30 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	create_back(t_list *lst, int content)
{
	t_list	*ptr;

	ptr = ft_lstnew(content);
	if (!ptr)
		return (0);
	ft_lstadd_back(&lst, ptr);
	return (1);
}

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*head;

	if (lst == NULL)
		return (NULL);
	head = ft_lstnew((*f)(lst->content));
	while (lst->next)
	{
		lst = lst->next;
		if (!create_back(head, (*f)(lst->content)))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
	}
	return (head);
}
