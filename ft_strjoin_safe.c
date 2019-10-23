/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:39:49 by aolen             #+#    #+#             */
/*   Updated: 2019/10/09 18:39:50 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strjoin_safe(char **str1, const char *str2)
{
	char *result;

	result = ft_strjoin(*str1, str2);
	ft_strdel(str1);
	return (result);
}
