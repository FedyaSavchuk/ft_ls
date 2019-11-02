/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:22:50 by aolen             #+#    #+#             */
/*   Updated: 2019/09/05 19:49:54 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str_dest;
	char	*str_src;
	char	*lastsrc;
	char	*lastdest;

	str_dest = (char*)dst;
	str_src = (char*)src;
	if (!dst && !src)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		lastsrc = str_src + (len - 1);
		lastdest = str_dest + (len - 1);
		while (len--)
			*lastdest-- = *lastsrc--;
	}
	return (dst);
}
