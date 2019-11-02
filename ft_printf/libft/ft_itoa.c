/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:29:23 by aolen             #+#    #+#             */
/*   Updated: 2019/09/05 20:20:13 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	mult_mult(int base, int exp)
{
	long int result;

	result = 1;
	while (exp-- > 0)
		result *= base;
	return (result);
}

char			*ft_itoa(int n)
{
	int			exp;
	char		*result;
	int			sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	exp = 0;
	n = -ABS(n);
	while (-mult_mult(10, exp + 1) >= n)
		exp++;
	if (!(result = (char*)malloc(sizeof(*result) * (exp + sign + 2))))
		return (NULL);
	result[exp + sign + 1] = 0;
	if (sign)
		result[0] = '-';
	while (exp > -1)
	{
		result[sign] = '0' - (n / mult_mult(10, exp));
		n = n % mult_mult(10, exp);
		exp--;
		sign++;
	}
	return (result);
}
