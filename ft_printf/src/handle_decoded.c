/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decoded.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:16:56 by aolen             #+#    #+#             */
/*   Updated: 2019/10/17 14:16:57 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define DEG_OF_5_7 "78125"
#define DEG_OF_5_71 "42351647362715016953416125033982098102569580078125"

void			get_degr_of_five(char **str, int degr)
{
	char	*tmp;

	tmp = ft_strnew(degr);
	if (degr >= 71)
	{
		ft_strcpy(tmp, DEG_OF_5_71);
		degr -= 71;
	}
	else if (degr-- > -1)
		ft_strcpy(tmp, "5");
	while (degr >= 71)
	{
		infin_mult(&tmp, DEG_OF_5_71);
		degr -= 71;
	}
	while (degr >= 1)
	{
		infin_mult(&tmp, "5");
		degr -= 1;
	}
	*str = ft_strdup(tmp);
	free(tmp);
}

static int		numlen(unsigned long mant)
{
	int		len;

	len = 0;
	while (mant > 0)
	{
		mant /= 10;
		len++;
	}
	return (len);
}

static void		get_str_mant(char **str, t_ld *l_info)
{
	int		i;

	i = numlen(l_info->mant);
	while (l_info->mant > 0)
	{
		i -= 1;
		(*str)[i] = (l_info->mant % 10) + '0';
		l_info->mant = l_info->mant / 10;
	}
}

static void		multiplication(char *five, int *degr, char **str)
{
	if (*degr < 0)
		infin_mult(str, five);
	while (*degr > 0)
	{
		infin_mult(str, "2");
		(*degr)--;
	}
}

void			handle_decoded(t_ld *l_info, char **str, int *final_degr)
{
	int			mant_denom;
	char		*five;

	five = NULL;
	mant_denom = 63;
	while ((unsigned char)l_info->mant == 0 && mant_denom > 7)
	{
		l_info->mant = l_info->mant >> 8;
		mant_denom -= 8;
	}
	*final_degr = l_info->exp - mant_denom;
	if (*final_degr < 0)
		get_degr_of_five(&five, -(*final_degr));
	(*str) = ft_strnew(ft_strlen(five) + 21);
	get_str_mant(str, l_info);
	multiplication(five, final_degr, str);
	ft_strdel(&five);
}
