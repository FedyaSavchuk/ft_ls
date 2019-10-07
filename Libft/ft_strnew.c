/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:45:53 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/06 16:01:52 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;
	char *start;

	if (size + 1 < size)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	start = str;
	while (size > 0)
	{
		*str = '\0';
		str++;
		size--;
	}
	*str = '\0';
	str = start;
	return (str);
}
