/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:38:52 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/06 12:47:51 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_same(const char *str1,
		const char *str2, size_t len, size_t save)
{
	size_t			i;

	i = 0;
	while (str1[i] == str2[i] && str2[i] != '\0' && len > save)
	{
		i++;
		save++;
	}
	if (str2[i] == '\0')
		return (1);
	return (0);
}

char		*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t			save;
	size_t			check_len;
	const char		*start;

	start = str2;
	check_len = 0;
	if (*str2 == '\0')
		return ((char *)str1);
	while (len > check_len && *str1)
	{
		if (*str1 == *str2 && *str1)
		{
			save = check_len;
			if (ft_check_same(str1, str2, len, save) == 1)
				return ((char *)str1);
			str2 = start;
		}
		str1++;
		check_len++;
	}
	return (NULL);
}
