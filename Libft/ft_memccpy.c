/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:36:17 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/04 17:39:03 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*new_str;
	unsigned char	*str;
	size_t			i;

	new_str = (unsigned char*)dst;
	str = (unsigned char*)src;
	i = 0;
	while (n > i)
	{
		new_str[i] = str[i];
		if (str[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
