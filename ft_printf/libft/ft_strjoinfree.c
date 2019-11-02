/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:37:36 by pparalax          #+#    #+#             */
/*   Updated: 2019/09/05 23:37:37 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char **s1, const char *s2)
{
	char	*res;
	size_t	length;

	if (!*s1 && !s2)
		return (0);
	if (!*s1)
		return (ft_strdup(s2));
	if (!s2)
		return (*s1);
	length = ft_strlen(*s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	ft_strcpy(res, *s1);
	ft_strcat(res, s2);
	ft_memdel((void**)s1);
	return (res);
}
