/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:45:05 by aolen             #+#    #+#             */
/*   Updated: 2019/09/10 20:52:55 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	for_people_who_think_that_this_is_needed(int sign)
{
	if (sign < 0)
		return (0);
	else
		return (-1);
}

int			ft_atoi(const char *str)
{
	int				i;
	unsigned long	numbers;
	unsigned long	prev;
	int				sign;

	i = 0;
	sign = 1;
	numbers = 0;
	prev = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-') && (str[i + 1] - '0' < 10)
		&& (str[i + 1] - '0' >= 0))
		i -= (sign = -1);
	else if (str[i] == '+' && ((str[i + 1] - '0' < 10)
			&& (str[i + 1] - '0' >= 0)))
		i++;
	while ((str[i] - '0' < 10) && (str[i] - '0' >= 0))
	{
		numbers = numbers * 10 + (str[i++] - '0');
		if (numbers < prev || numbers >= 9223372036854775807)
			return (for_people_who_think_that_this_is_needed(sign));
		prev = numbers;
	}
	return (numbers * sign);
}
