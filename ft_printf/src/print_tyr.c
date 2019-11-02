/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tyr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:18:53 by aolen             #+#    #+#             */
/*   Updated: 2019/10/17 14:18:53 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_t(char **arr)
{
	int j;

	j = 0;
	while (arr[j])
	{
		ft_putstr(arr[j]);
		ft_putchar('\n');
		j++;
	}
}

void	print_y(char ***arr)
{
	int i;
	int j;

	j = 0;
	while (arr[j])
	{
		i = 0;
		while (arr[j][i])
		{
			ft_putstr(arr[j][i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
