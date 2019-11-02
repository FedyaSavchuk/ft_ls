/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 11:48:51 by aolen             #+#    #+#             */
/*   Updated: 2019/09/04 18:03:28 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int k;
	long int n_long;

	k = 1;
	n_long = 0 + n;
	if (n < 0)
	{
		n_long *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
	}
	while (n_long)
	{
		k = k * 10 + n_long % 10;
		n_long /= 10;
	}
	while (k != 1)
	{
		ft_putchar_fd('0' + k % 10, fd);
		k /= 10;
	}
	return ;
}
