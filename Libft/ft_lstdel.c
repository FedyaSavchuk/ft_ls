/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:33:47 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/11 16:33:55 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_elem;
	t_list	*prev_elem;

	if (!*alst || !del)
		return ;
	prev_elem = *alst;
	next_elem = prev_elem->next;
	while (next_elem != NULL)
	{
		next_elem = prev_elem->next;
		(*del)((prev_elem)->content, (prev_elem)->content_size);
		free(prev_elem);
		prev_elem->next = NULL;
		prev_elem = next_elem;
	}
	*alst = NULL;
}
