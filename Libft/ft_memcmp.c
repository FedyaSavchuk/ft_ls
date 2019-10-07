/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:31:27 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/05 13:44:33 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t len)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char *)str1;
	ptr2 = (unsigned char *)str2;
	while (len > 0)
	{
		if (*ptr1 < *ptr2)
			return (*ptr1 - *ptr2);
		else if (*ptr1 > *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		len--;
	}
	return (0);
}
