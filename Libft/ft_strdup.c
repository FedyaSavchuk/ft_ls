/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:53:08 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/05 15:30:18 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy_str;
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	copy_str = (char *)malloc(sizeof(char) * (len + 1));
	if (copy_str == NULL)
		return (NULL);
	len = 0;
	while (str[len])
	{
		copy_str[len] = str[len];
		len++;
	}
	copy_str[len] = '\0';
	return (copy_str);
}
