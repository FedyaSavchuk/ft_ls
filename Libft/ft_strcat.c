/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:28:02 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/08 12:27:20 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *append)
{
	int len;
	int i;

	len = 0;
	while (dst[len] != '\0')
		len++;
	i = 0;
	while (append[i] != '\0')
	{
		dst[len] = append[i];
		len++;
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
