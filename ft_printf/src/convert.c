/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:16:35 by aolen             #+#    #+#             */
/*   Updated: 2019/10/17 14:16:36 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int			convert_d(va_list *argv)
{
	if (g_flags->hh)
		return ((long long int)(char)va_arg(*argv, int));
	if (g_flags->h)
		return ((long long int)(short int)va_arg(*argv, int));
	if (g_flags->ll)
		return ((long long int)va_arg(*argv, long long int));
	if (g_flags->l)
		return ((long long int)va_arg(*argv, long int));
	return (va_arg(*argv, int));
}

unsigned long long int	convert_u(va_list *argv)
{
	if (g_flags->hh)
		return ((unsigned char)va_arg(*argv, unsigned int));
	if (g_flags->h)
		return ((unsigned short int)va_arg(*argv, unsigned int));
	if (g_flags->ll)
		return (va_arg(*argv, unsigned long long int));
	if (g_flags->l)
		return (va_arg(*argv, unsigned long int));
	return (va_arg(*argv, unsigned int));
}

long double				convert_f(va_list *argv)
{
	if (g_flags->l)
		return ((double)va_arg(*argv, double));
	else if (g_flags->cap_l)
		return (va_arg(*argv, long double));
	return (va_arg(*argv, double));
}

void					add_cut(char **snbr)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ft_strlen(*snbr) < (unsigned long)g_flags->cut)
	{
		tmp = ft_strnew(g_flags->cut);
		while (i++ < (int)(g_flags->cut - ft_strlen(*snbr)))
			ft_strcat(tmp, "0");
		ft_strcat(tmp, *snbr);
		free(*snbr);
		*snbr = tmp;
	}
}
