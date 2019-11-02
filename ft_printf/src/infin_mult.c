/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:17:18 by aolen             #+#    #+#             */
/*   Updated: 2019/10/17 14:17:19 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "printf.h"
#include "libft.h"

static void		check_overlay(int **arr, int len)
{
	int i;

	i = len;
	while (--i > 0)
		if ((*arr)[i] >= 10)
		{
			(*arr)[i - 1] += (*arr)[i] / 10;
			(*arr)[i] = (*arr)[i] % 10;
		}
}

static int		*ft_processing(char *m1, char *n2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	unsigned int	tmp;
	int				*arr;

	len = ft_strlen(m1) + ft_strlen(n2);
	arr = ft_memalloc(sizeof(int) * (len + 1));
	arr[len] = -5;
	i = -1;
	while (m1[++i] != '\0')
	{
		j = 0;
		while (n2[j] != '\0')
		{
			tmp = (m1[i] - '0') * (n2[j] - '0');
			arr[i + j] += tmp / 10;
			arr[i + ++j] += tmp % 10;
		}
	}
	check_overlay(&arr, len);
	i = len;
	return (arr);
}

void			infin_mult(char **m1, char *m2)
{
	int					*arr;
	unsigned int		i;
	unsigned int		j;

	if ((*m1)[0] == 0 || m2[0] == 0)
	{
		(*m1)[0] = '0';
		(*m1)[1] = '\0';
		return ;
	}
	arr = ft_processing(*m1, m2);
	i = 0;
	j = 0;
	if (i == 0 && arr[i] == 0)
		i++;
	while (arr[i] != -5)
	{
		(*m1)[j] = arr[i] + '0';
		i++;
		j++;
	}
	(*m1)[j] = '\0';
	free(&arr[0]);
}
