/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orizhiy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:18:30 by orizhiy           #+#    #+#             */
/*   Updated: 2016/12/05 12:31:58 by orizhiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;

	if (!lst || !f)
		return (NULL);
	lst3 = (*f)(lst);
	lst1 = ft_lstnew(lst3->content, lst3->content_size);
	if (lst1)
	{
		lst2 = lst1;
		lst = lst->next;
		while (lst)
		{
			lst3 = (*f)(lst);
			lst2->next = ft_lstnew(lst3->content, lst3->content_size);
			if (!(lst2->next))
				return (NULL);
			lst2 = lst2->next;
			lst = lst->next;
		}
	}
	return (lst1);
}
