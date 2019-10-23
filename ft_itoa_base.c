/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:09:55 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 13:15:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"

char g_hex[17] = "0123456789abcdef";
char g_hex_big[17] = "0123456789ABCDEF";

long int	ft_power(long long int nb, int exp)
{
	long int lnbr;

	lnbr = 0 + nb;
	if (exp < 0)
		return (0);
	else if (exp == 0)
		return (1);
	else if (exp == 1)
		return (lnbr);
	else if (exp % 2 == 0)
		return (ft_power(lnbr, exp / 2) * ft_power(lnbr, exp / 2));
	else
		return (ft_power(lnbr, exp - 1) * lnbr);
}

int			ft_check_base(char *str)
{
	int i;
	int j;

	i = 0;
	if (!(str[0]) || !(str[1]))
		return (0);
	while (str[i])
	{
		if ((str[i] < ' ') || (str[i] == 127))
			return (0);
		else if ((str[i] == '+') || (str[i] == '-'))
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			*ft_translate(long long int nbr, int base_num, int *res_ar)
{
	int			i;
	int			temp;
	long int	lnbr;

	i = 0;
	lnbr = 0 + nbr;
	if (nbr < 0)
		lnbr *= -1;
	while (i++ < 64)
		res_ar[i] = 0;
	i = 0;
	while (ft_power(base_num, i) < lnbr)
		i++;
	while (i > -1)
	{
		temp = lnbr / ft_power(base_num, i);
		res_ar[i] = temp;
		lnbr -= temp * ft_power(base_num, i);
		i--;
	}
	return (res_ar);
}

char		*ft_itoa_base(long long int nbr, int base, char reg)
{
	int			j;
	int			res_ar[64];
	char		*s;
	char		*hex;

	hex = reg > 64 && reg < 91 ? g_hex_big : g_hex;
	ft_translate(nbr, base, res_ar);
	j = 64;
	while ((res_ar[j] == 0) && (j > 0))
		j--;
	s = ft_memalloc(j + 2 + 1);
	if (nbr < 0)
		s[j + 1] = '-';
	s[++j + 1] = 0;
	while (--j > -1)
		s[j] = hex[res_ar[j]];
	ft_strrev(s);
	return (s);
}
