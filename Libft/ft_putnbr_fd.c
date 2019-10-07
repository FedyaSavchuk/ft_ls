/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:19:27 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/07 20:21:24 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char print;
	long p;

	if (fd < 0)
		return ;
	p = n;
	if (p < 0)
	{
		p = p * -1;
		write(fd, "-", 1);
	}
	if (p >= 10)
	{
		ft_putnbr_fd(p / 10, fd);
		print = p % 10 + '0';
		write(fd, &print, 1);
	}
	if (p < 10)
	{
		print = p + '0';
		write(fd, &print, 1);
	}
}
