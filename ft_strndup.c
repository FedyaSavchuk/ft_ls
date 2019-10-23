/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:44:01 by aolen             #+#    #+#             */
/*   Updated: 2019/10/09 20:44:02 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strndup(const char *str, int n)
{
	char	*copy_str;
	int		len;

	len = 0;
	while (str[len] != '\0' && len < n)
		len++;
	copy_str = (char *)malloc(sizeof(char) * (len + 1));
	if (copy_str == NULL)
		return (NULL);
	len = 0;
	while (str[len] && len < n)
	{
		copy_str[len] = str[len];
		len++;
	}
	copy_str[len] = '\0';
	return (copy_str);
}
