/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:17:37 by aolen             #+#    #+#             */
/*   Updated: 2019/10/17 14:17:38 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(char c)
{
	if (g_flags->minus)
		ft_putchar(c);
	ft_putchars(' ', g_flags->min_width - 1);
	if (!g_flags->minus)
		ft_putchar(c);
	return (0);
}
