/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:25:22 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/05 17:27:25 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!src || !dst)
		return (0);
	i = 0;
	j = 0;
	while (src[i])
		i++;
	while (src[j] && (j + 1 < size))
	{
		dst[j] = src[j];
		j++;
	}
	if (size > j)
		dst[j] = '\0';
	return (i);
}
