/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:02:03 by aolen             #+#    #+#             */
/*   Updated: 2019/10/15 14:02:04 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		round_last(char *str, int k)
{
	int	i;

	i = 2;
	if (str[k + 1] == '\0')
		return (0);
	else if (str[k + 1] && str[k + 1] > '5')
		return (1);
	else if (str[k + 1] && str[k + 1] < '5')
		return (0);
	while (str[k + i] != '\0')
		if (str[k + i++] > '0')
			return (1);
	if ((str[k] - '0') % 2 == 0)
		return (0);
	return (1);
}

void	check_round(char **str, int j)
{
	(*str)[j + 1] = 0;
	while (j > 0 && (*str)[j] > '9')
	{
		(*str)[j] = '0';
		if ((*str)[j - 1] == '.')
			j--;
		if ((j - 1) >= 0)
			(*str)[j - 1] += 1;
		j--;
	}
}

void	handle_integer(char **result, int i, char *str)
{
	int		j;
	int		k;

	j = 1;
	k = 0;
	if (i <= 0 && (++k + 1))
		(*result)[j++] = '0';
	while (i-- > 0 && str[k] != '\0')
		(*result)[j++] = str[k++];
	if (i >= -1)
		(*result)[j - 1] += round_last(str, k - 1);
	check_round(result, j - 1);
	if (g_flags->grill == 1)
		(*result)[j++] = '.';
	(*result)[j] = '\0';
}

int		is_num_valid(t_ld *l_info, char **str)
{
	int		i;

	i = 16383;
	if (l_info->pos_p == 1 || l_info->exp_2 < 1)
		l_info->exp_2 += 1;
	else if (l_info->exp_2 == 0)
		l_info->pos_p = -1;
	else
		l_info->exp_2 -= i;
	if (l_info->exp_2 == 16384)
	{
		if ((l_info->mant << 1) != 0)
			*str = ft_strdup("nan");
		else
		{
			*str = ft_strdup("inf");
		}
		return (0);
	}
	return (1);
}
