/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:36:05 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/04 15:36:08 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*new_str;
	unsigned char	*str;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	new_str = dst;
	str = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}
