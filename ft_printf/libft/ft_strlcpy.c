/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:51:47 by aolen             #+#    #+#             */
/*   Updated: 2019/09/07 15:46:05 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	src_len;

	if (!src || !dest)
		return (0);
	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	while (src[i] && (i + 1 < size))
	{
		dest[i] = src[i];
		i++;
	}
	if (size >= i + 1)
		dest[i] = 0;
	return (src_len);
}
