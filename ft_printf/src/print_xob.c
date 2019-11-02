/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:20:20 by aolen             #+#    #+#             */
/*   Updated: 2019/10/17 14:20:21 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_format_xo(char ns, int nbr)
{
	char	*tmp;

	tmp = ft_uitoa_base(nbr, 8, 'a');
	if (ns == 'o' && ((g_flags->cut > (int)ft_strlen(tmp)) ||
		(!nbr && !g_flags->dote)))
	{
		free(tmp);
		return ;
	}
	if (g_flags->grill && (nbr || (g_flags->cut <= (int)ft_strlen(tmp)
		&& g_flags->min_width && ns == 'o') || ns == 'p'))
		ft_putchar('0');
	if (g_flags->grill && ns != 'o' && (nbr || ns == 'p'))
		ft_putchar((ns == 'p') ? 'x' : ns);
	free(tmp);
}

static int	get_format_xo(char ns, int nbr)
{
	char	*tmp;
	int		res;

	res = 0;
	if (!g_flags->grill)
		return (0);
	tmp = ft_uitoa_base(nbr, 8, 'a');
	if (ns == 'o' && ((g_flags->cut > (int)ft_strlen(tmp)) ||
		(!nbr && !g_flags->dote)))
	{
		free(tmp);
		return (0);
	}
	if (g_flags->grill && (nbr || (g_flags->cut <= (int)ft_strlen(tmp)
		&& g_flags->min_width && ns == 'o') || ns == 'p'))
		res++;
	if (g_flags->grill && ns != 'o' && (nbr || ns == 'p'))
		res++;
	free(tmp);
	return (res);
}

int			get_len1(char *snbr)
{
	if (!(snbr[0] == '0' && !snbr[1]) || !g_flags->dote)
		return (ft_strlen(snbr));
	return (0);
}

int			kost(char ns)
{
	return (!(g_flags->dote && !g_flags->cut) ||
		(g_flags->grill && ns == 'o' && !g_flags->min_width));
}

int			print_xxo(unsigned long long int nbr, char ns)
{
	char	*snbr;

	g_flags->grill = (ns == 'p') ? 1 : g_flags->grill;
	if (ns == 'b')
		snbr = ft_uitoa_base(nbr, 2, 'a');
	else
		snbr = ft_uitoa_base(nbr, (ns == 'o') ? 8 : 16, ns);
	add_cut(&snbr);
	if (g_flags->minus)
		print_format_xo(ns, nbr);
	else
	{
		if (g_flags->zero && !g_flags->dote)
			print_format_xo(ns, nbr);
		ft_putchars((g_flags->zero && !g_flags->dote) ? '0' : ' ',
				g_flags->min_width - get_len1(snbr) - get_format_xo(ns, nbr));
		if (!(g_flags->zero && !g_flags->dote))
			print_format_xo(ns, nbr);
	}
	ft_putstr(kost(ns) ? snbr : 0);
	if (g_flags->minus)
		ft_putchars(' ',
				g_flags->min_width - get_len1(snbr) - get_format_xo(ns, nbr));
	free(snbr);
	return (1);
}
