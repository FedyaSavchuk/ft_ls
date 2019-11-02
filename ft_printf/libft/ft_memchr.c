/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:01:49 by aolen             #+#    #+#             */
/*   Updated: 2019/09/06 17:13:47 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	str = (unsigned char*)s;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void*)(str + i));
		i++;
	}
	return (NULL);
}
