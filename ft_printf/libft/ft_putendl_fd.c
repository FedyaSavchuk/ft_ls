/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:58:43 by aolen             #+#    #+#             */
/*   Updated: 2019/09/07 15:33:26 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (*(s + i))
	{
		ft_putchar_fd(*(s + i), fd);
		i += 1;
	}
	ft_putchar_fd('\n', fd);
	return ;
}
