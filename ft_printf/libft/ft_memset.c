/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:02:38 by aolen             #+#    #+#             */
/*   Updated: 2019/09/04 16:33:47 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	ch;
	unsigned char	*str;

	i = 0;
	ch = c;
	str = (unsigned char*)b;
	while (i < len)
	{
		str[i] = ch;
		i++;
	}
	return (b);
}
