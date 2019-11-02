/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:17:45 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/29 19:17:48 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_persent_and_space(int i)
{
	ft_putchar('%');
	ft_putchars((g_flags->zero) ? '0' : ' ', i * -1 - 1);
	return (0);
}

int		check_double_percents(const char *format, int i)
{
	if (format[g_iter] == '%' && ++i)
	{
		g_flags->zero = (format[g_iter + 1] == '0') ? 1 : 0;
		while (format[g_iter + i] == ' ' || format[g_iter + i] == '.' ||
			format[g_iter + i] == '-' || ft_isdigit(format[g_iter + i]))
			i++;
		if (format[g_iter + i] == '%')
		{
			i = g_iter += i;
			if (i > 1 && format[i - 1] >= '0' && format[i - 1] <= '9' && i--)
			{
				while ((format[i] >= '0' && format[i] <= '9'))
					i--;
				i += (format[i] == '%') ? 1 : 0;
				ft_putchars((g_flags->zero) ? '0' : ' ',
				(i = ft_atoi(&format[i])) > 0 ? i - 1 : 0);
				if (i < 0)
					return (put_persent_and_space(i));
			}
			return (1);
		}
	}
	return (0);
}

void	choose_spec(char spec, va_list *argv)
{
	if (spec == 'd' || spec == 'i')
		print_di(convert_d(argv));
	else if (spec == 'u')
		print_u(convert_u(argv));
	else if (spec == 'x' || spec == 'X' || spec == 'o' || spec == 'b')
		print_xxo(convert_u(argv), spec);
	else if (spec == 't')
		print_t(va_arg(*argv, char **));
	else if (spec == 's')
		print_s(va_arg(*argv, char *), 0);
	else if (spec == 'c')
		print_c(va_arg(*argv, int));
	else if (spec == 'y')
		print_y(va_arg(*argv, char ***));
	else if (spec == 'f')
		print_lf(convert_f(argv));
	else if (spec == 'p')
		print_xxo(va_arg(*argv, unsigned long int), 'p');
	else if (spec == 'r')
		print_s(va_arg(*argv, char *), 'r');
}

int		free_g(void)
{
	free(g_flags);
	return (g_giter);
}

int		ft_printf(const char *format, ...)
{
	va_list		argv;
	char		spec;

	g_iter = 0;
	g_giter = 0;
	va_start(argv, format);
	if (!(g_flags = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (0);
	while (format[g_iter])
	{
		if (format[g_iter] != '%' || check_double_percents(format, 0))
			ft_putchar(format[g_iter]);
		else
		{
			g_iter++;
			clear_flags();
			if (!(spec = read_flags(format, &argv, g_iter - 1)))
				continue ;
			choose_spec(spec, &argv);
		}
		g_iter++;
	}
	va_end(argv);
	return (free_g());
}
