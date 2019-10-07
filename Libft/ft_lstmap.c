/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:25:45 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/12 14:40:31 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		ft_del(void *content, size_t content_size)
{
	ft_memdel(&content);
	content_size = 0;
}

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_head;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new_head = (*f)(lst);
	if (new_head == NULL)
	{
		free(new_head);
		return (NULL);
	}
	new = new_head;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new->next = (*f)(lst);
		if (new->next == NULL)
		{
			ft_lstdel(&new_head, ft_del);
			return (NULL);
		}
		new = new->next;
	}
	return (new_head);
}
