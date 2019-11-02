/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:28:36 by aolen             #+#    #+#             */
/*   Updated: 2019/09/05 20:04:41 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*str_src;
	char			*str_dst;
	char			ch;

	str_src = (char*)src;
	str_dst = (char*)dst;
	ch = c;
	i = 0;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		if (str_src[i] == ch)
		{
			return ((void*)&str_dst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
