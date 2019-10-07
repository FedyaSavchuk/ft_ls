/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:59:50 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/05 19:00:08 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *append, size_t n)
{
	int		len;
	size_t	i;

	len = 0;
	while (dst[len] != '\0')
		len++;
	i = 0;
	while (i < n && append[i] != '\0')
	{
		dst[len] = append[i];
		len++;
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
