/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:49:31 by aolen             #+#    #+#             */
/*   Updated: 2019/09/06 13:58:43 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\0')
		return (1);
	return (0);
}

char		*ft_strtrim(const char *s)
{
	char		*clear_copy;
	int			len;
	const char	*begin;

	if (!s)
		return (NULL);
	begin = s;
	while (*begin != '\0' && isspace(*begin))
		begin++;
	len = ft_strlen(begin);
	if (len == 0)
		return (ft_strnew(1));
	while (isspace(begin[len - 1]) && len > 0)
		len--;
	if (!(clear_copy = ft_strnew(len)))
		return (NULL);
	ft_strncpy(clear_copy, begin, len);
	clear_copy[len] = 0;
	return (clear_copy);
}
