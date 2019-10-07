/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:31:08 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/05 13:31:12 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t len)
{
	unsigned char *str;

	str = (unsigned char *)arr;
	while (len > 0)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		len--;
		str++;
	}
	return (NULL);
}
