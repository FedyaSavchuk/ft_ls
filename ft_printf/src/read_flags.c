/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:20:32 by aolen             #+#    #+#             */
/*   Updated: 2019/10/17 14:20:32 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		clear_flags(void)
{
	g_flags->zero = 0;
	g_flags->minus = 0;
	g_flags->plus = 0;
	g_flags->grill = 0;
	g_flags->dote = 0;
	g_flags->space = 0;
	g_flags->h = 0;
	g_flags->hh = 0;
	g_flags->l = 0;
	g_flags->ll = 0;
	g_flags->cap_l = 0;
	g_flags->min_width = 0;
	g_flags->cut = 0;
	return (0);
}

void	star(const char *format, int i, va_list *argv)
{
	if (format[i - 1] == '.')
	{
		g_flags->cut = va_arg(*argv, int);
		g_flags->dote = (g_flags->cut >= 0) ? g_flags->dote : 0;
		g_flags->cut = (g_flags->cut >= 0) ? g_flags->cut : 0;
	}
	else if (format[i + 1] <= '9' && format[i + 1] >= '0')
		va_arg(*argv, int);
	else
	{
		g_flags->min_width = va_arg(*argv, int);
		g_flags->minus = (g_flags->min_width < 0) ? 1 : g_flags->minus;
		g_flags->min_width = ft_abs(g_flags->min_width);
	}
}

int		a_to_i(const char *format, int *i, char c)
{
	if (c == 'w')
	{
		while (ft_isdigit(format[*i]))
			g_flags->min_width = g_flags->min_width * 10 +
		(format[(*i)++] - '0');
		(*i)--;
	}
	else
	{
		(*i)++;
		while (ft_isdigit(format[(*i)]))
			g_flags->cut = g_flags->cut * 10 + (format[(*i)++] - '0');
		(*i)--;
	}
	return (1);
}

int		check_flags(char c)
{
	return (c != 'c' && c != 's' && c != 'p' && c != 'd' && c != 'r'
		&& c != 'i' && c != 'o' && c != 'u' && c != 't' && c != 'y'
		&& c != 'x' && c != 'X' && c != 'f' && c != '\0');
}

char	read_flags(const char *f, va_list *argv, int i)
{
	while (check_flags(f[++i]))
	{
		g_flags->space = (f[i] == ' ') ? 1 : g_flags->space;
		g_flags->minus = (f[i] == '-') ? 1 : g_flags->minus;
		g_flags->plus = (f[i] == '+') ? 1 : g_flags->plus;
		g_flags->grill = (f[i] == '#') ? 1 : g_flags->grill;
		g_flags->hh = (f[i] == 'h' && f[i + 1] == 'h') ? 1 : g_flags->hh;
		g_flags->h = (f[i] == 'h') ? 1 : g_flags->h;
		g_flags->ll = (f[i] == 'l' && f[i + 1] == 'l') ? 1 : g_flags->ll;
		g_flags->l = (f[i] == 'l') ? 1 : g_flags->l;
		g_flags->cap_l = (f[i] == 'L') ? 1 : g_flags->cap_l;
		g_flags->zero = (f[i] == '0') ? 1 : g_flags->zero;
		(f[i] == '*') ? star(f, i, argv) : 0;
		(f[i] <= '9' && f[i] >= '1') ? a_to_i(f, &i, 'w') : 0;
		g_flags->dote = (f[i] == '.') ? a_to_i(f, &i, 'c') : g_flags->dote;
		if (!(f[i] == ' ' || f[i] == '-' || f[i] == '+' ||
			f[i] == '#' || f[i] == 'h' || f[i] == 'l' ||
			f[i] == 'L' || f[i] == '0' || f[i] == '*' ||
			f[i] == '.' || (f[i] <= '9' && f[i] >= '1')))
			return (clear_flags());
	}
	return (f[g_iter = i]);
}
