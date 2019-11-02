/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:09:38 by aolen             #+#    #+#             */
/*   Updated: 2019/09/09 15:26:13 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *elem;

	elem = *alst;
	if (!(alst) || !(*alst) || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	(*alst) = NULL;
}
