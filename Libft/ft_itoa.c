/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:32:46 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/07 18:41:59 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*make_string(char *str, long num, int len)
{
	str[len] = '\0';
	len--;
	while (num > 9)
	{
		str[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	str[len] = num + '0';
	if (len != 0)
	{
		len--;
		str[len] = '-';
	}
	return (str);
}

char		*ft_itoa(int n)
{
	long	save;
	long	num;
	int		len;
	char	*str;

	len = 0;
	num = n;
	if (num < 0)
	{
		len++;
		num = num * -1;
	}
	save = num;
	if (num == 0)
		len++;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (make_string(str, save, len));
}
