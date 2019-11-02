/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:39:59 by aolen             #+#    #+#             */
/*   Updated: 2019/09/05 19:09:01 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	ch;

	len = ft_strlen(s);
	ch = c;
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char*)&s[len]);
		len--;
	}
	return (NULL);
}
