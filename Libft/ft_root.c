/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:35:35 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/13 12:35:37 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_check_root(unsigned long long root)
{
	if (root > 1000000000000000000)
		root = root / 1000000000;
	else if (root > 10000000000000000)
		root = root / 100000000;
	else if (root > 100000000000000)
		root = root / 10000000;
	else if (root > 1000000000000)
		root = root / 1000000;
	else if (root > 10000000000)
		root = root / 100000;
	else if (root > 100000000)
		root = root / 10000;
	else if (root > 1000000)
		root = root / 1000;
	else if (root > 10000)
		root = root / 100;
	return (root);
}

unsigned long			ft_root(unsigned long long num)
{
	unsigned long long root;
	unsigned long long i;

	root = num;
	i = 0;
	if (root + 1 < root)
		return (0);
	if (root == 1)
		return (root);
	i = ft_check_root(root);
	while (i <= root)
	{
		if (i * i == root)
			return (i);
		i++;
	}
	return (0);
}
