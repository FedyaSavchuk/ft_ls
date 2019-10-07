/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:54:13 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/05 20:59:36 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search)
{
	char	*s;
	int		len;

	s = (char *)str;
	len = 0;
	while (s[len] != '\0')
		len++;
	while (len >= 0)
	{
		if (*s == search)
			return (s);
		s++;
		len--;
	}
	return (NULL);
}
