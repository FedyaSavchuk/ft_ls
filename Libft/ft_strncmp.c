/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:39:55 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/06 13:41:11 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t len)
{
	while ((unsigned char)*str1 != '\0' && (unsigned char)*str2 != '\0'
	&& (unsigned char)*str1 == (unsigned char)*str2 && len > 0)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
		len--;
	}
	if (len == 0)
		return (0);
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
