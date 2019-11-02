/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:34:42 by aolen             #+#    #+#             */
/*   Updated: 2019/09/05 19:08:21 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int needle_pos;
	int i;

	i = 0;
	needle_pos = 0;
	if (!*(needle))
		return ((char *)haystack);
	while (haystack[i])
	{
		while ((haystack[i + needle_pos]) && (haystack[i + needle_pos]
										== needle[needle_pos]))
		{
			needle_pos++;
			if (needle[needle_pos] == '\0')
				return ((char*)&haystack[i]);
		}
		needle_pos = 0;
		i++;
	}
	return (NULL);
}
