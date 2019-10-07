/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:42:00 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/06 12:43:13 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int			i;
	const char	*start;
	const char	*search;

	search = str1;
	start = str2;
	i = 0;
	if (*str2 == '\0')
		return ((char *)str1);
	while (*str1)
	{
		if (*str1 == *str2)
		{
			search = str1;
			while (str1[i] == str2[i] && str2[i] != '\0')
				i++;
			if (str2[i] == '\0')
				return ((char *)search);
			i = 0;
			str2 = start;
		}
		str1++;
	}
	return (NULL);
}
