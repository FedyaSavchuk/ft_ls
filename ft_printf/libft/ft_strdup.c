/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:10:45 by aolen             #+#    #+#             */
/*   Updated: 2019/09/09 15:32:30 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	if ((i + 1 == 0) || !(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	while (i + 1 > 0)
	{
		str[i] = src[i];
		i--;
	}
	return (str);
}
