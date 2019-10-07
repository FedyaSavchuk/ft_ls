/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:03:10 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/06 11:40:46 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int search)
{
	char	*s;
	char	*ch;
	int		len;

	ch = NULL;
	s = (char *)str;
	len = 0;
	while (s[len] != '\0')
		len++;
	while (len >= 0)
	{
		if (*s == search)
			ch = s;
		s++;
		len--;
	}
	return (ch);
}
