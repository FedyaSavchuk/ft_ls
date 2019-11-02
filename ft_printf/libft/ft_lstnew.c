/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:39:05 by aolen             #+#    #+#             */
/*   Updated: 2019/09/06 20:29:51 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_el;

	if (!(new_el = (t_list*)malloc(sizeof(*new_el))))
		return (NULL);
	new_el->next = NULL;
	if (!content)
	{
		new_el->content = NULL;
		new_el->content_size = 0;
		return (new_el);
	}
	if (!(new_el->content = ft_memalloc(content_size)))
	{
		free(new_el);
		return (NULL);
	}
	ft_memcpy(new_el->content, content, content_size);
	new_el->content_size = content_size;
	return (new_el);
}
