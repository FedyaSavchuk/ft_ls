/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:05:59 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/07 11:40:05 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str_join = (char *)malloc(sizeof(char) * len + 1);
	if (str_join == NULL)
		return (NULL);
	ft_strcpy(str_join, s1);
	ft_strcat(str_join, s2);
	return (str_join);
}
