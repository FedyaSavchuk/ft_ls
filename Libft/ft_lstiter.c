/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:07:41 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/11 17:07:43 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	t_list	*next_elem;

	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		next_elem = lst->next;
		(*f)(lst);
		lst = next_elem;
	}
}
