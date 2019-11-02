/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:18:25 by aolen             #+#    #+#             */
/*   Updated: 2019/10/17 14:18:25 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#define MAX_LEN 8192

static char	handle_flags(char *s, char **out)
{
	char result;

	result = 0;
	if (g_flags->plus)
		result = '+';
	else if (g_flags->space)
		result = ' ';
	*out = (result != 0) ? s + 1 : s;
	return (result);
}

static void	print_double(char *str, int len)
{
	if (!ft_isalnum(str[0]) && str[1] == 'n')
		return (void)print_s(str + 1, 1);
	else if ((!ft_isalnum(str[0]) && str[1] == 'i') || ft_isalpha(str[0]))
		return (void)print_s(str, 1);
	if (g_flags->minus)
	{
		ft_putstr(str);
		ft_putchars(' ', g_flags->min_width - len);
		return ;
	}
	if (!ft_isalnum(str[0]) && g_flags->zero)
		ft_putchar(*str++);
	if (g_flags->zero && g_flags->min_width)
		ft_putchars('0', g_flags->min_width - len);
	else if (g_flags->min_width)
	{
		ft_putchars(' ', g_flags->min_width - len);
		if (!ft_isalnum(str[0]))
			ft_putchar(*str++);
	}
	ft_putstr(str);
}

/*
**	Function: print_lf
**	--------------------------
**	main function for  float handling, get float format number
**	convert it to long double, after what handling flags (+,-, )
**	and convert it to string for output according to a needed precision
**	and length of integer part
**
**	num:	long long float (long double) number to print
**
**	returns:	void
*/

void		print_lf(long double num)
{
	char	s[MAX_LEN];
	char	*out;
	char	*temp;
	t_un	g_u;

	g_u.num = num;
	ft_bzero(s, MAX_LEN);
	if ((unsigned char)g_u.ar[9] >> 7 == 1)
	{
		s[0] = '-';
		out = s + 1;
	}
	else
		s[0] = handle_flags(s, &out);
	if (g_flags->dote == 0)
		g_flags->cut = 6;
	print_f(&temp, g_u);
	ft_strcpy(out, temp);
	ft_strdel(&temp);
	print_double(s, ft_strlen(s));
}
