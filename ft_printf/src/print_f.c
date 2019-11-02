/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:46:59 by aolen             #+#    #+#             */
/*   Updated: 2019/10/16 13:47:00 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MAX_POWER_OF_LDBL 16383

static void	print_res(char *result, char **str)
{
	if (*str)
		free(*str);
	if (result[0] == '0' && result[1] != '.')
		result++;
	*str = ft_strdup(result);
}

static int	form_number(char *result, int *i, int *j, char **str)
{
	int k;

	k = 0;
	if ((*i) <= 0)
	{
		result[(*j)++] = '0';
		result[(*j)++] = '.';
		while ((*i)++ < 0 && g_flags->cut-- > 1)
			result[(*j)++] = '0';
		while ((*str)[k] != '\0' && g_flags->cut-- > 1)
			result[(*j)++] = (*str)[k++];
	}
	else
	{
		while ((*i)-- > 0 && (*str)[k] != '\0')
			result[(*j)++] = (*str)[k++];
		result[(*j)++] = '.';
		while ((*str)[k] != '\0' && g_flags->cut-- > 1)
			result[(*j)++] = (*str)[k++];
		(*i) += 2;
	}
	return (k);
}

static void	print_num(char **str, int degr, int j)
{
	char	*result;
	int		i;
	int		k;

	i = ft_strlen((*str)) - degr;
	result = ft_strnew((i > 0 ? i : 1) + g_flags->cut + 2);
	result[j++] = '0';
	if (g_flags->dote == 1 && g_flags->cut == 0)
		handle_integer(&result, i, (*str));
	else
	{
		k = form_number(result, &i, &j, str);
		if (!(*str)[k])
			while (g_flags->cut-- > 0)
				result[j++] = '0';
		else if (i == 0)
			result[j] = '0' + ((*str)[0] >= '5' ? 1 : 0);
		else if (i < 0)
			result[j] = '0';
		else
			result[j] = (*str)[k] + round_last((*str), k);
		check_round(&result, j);
	}
	print_res(result, str);
	free(result);
}

static void	transform_dbl(t_ld **dbl_sruct, t_un g_u)
{
	t_ld		*l_info;

	l_info = *dbl_sruct;
	l_info->sign = (unsigned char)g_u.ar[9] >> 7;
	l_info->pos_p = (unsigned char)(g_u.ar[9] << 1) >> 7;
	l_info->exp = ((unsigned int)((unsigned char)(g_u.ar[9] << 2) >> 2) << 8)
				| g_u.ar[8];
	l_info->exp_2 = ((unsigned int)((unsigned char)(g_u.ar[9] << 2) >> 2) << 8)
					| (unsigned char)g_u.ar[8];
	if (l_info->pos_p == 1 || l_info->exp < 0)
		l_info->exp += 1;
	else if (l_info->exp != 0)
		l_info->exp -= MAX_POWER_OF_LDBL;
}

void		print_f(char **str, t_un g_u)
{
	t_ld		*l_info;
	int			i;
	int			final_degr;

	l_info = ft_memalloc(sizeof(*l_info));
	transform_dbl(&l_info, g_u);
	i = 8;
	l_info->mant = 0;
	while (--i >= 0)
	{
		l_info->mant = l_info->mant << 8;
		l_info->mant |= (unsigned char)g_u.ar[i];
	}
	if (!is_num_valid(l_info, str))
		return ;
	handle_decoded(l_info, str, &final_degr);
	print_num(str, -final_degr, 0);
	free(l_info);
}
