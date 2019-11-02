/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:35:12 by aolen             #+#    #+#             */
/*   Updated: 2019/09/07 15:30:34 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub_s;

	if (!s)
		return (NULL);
	if (!(sub_s = (char*)ft_memalloc(len + 1)))
		return (NULL);
	ft_strncpy(sub_s, s + start, len);
	return (sub_s);
}
