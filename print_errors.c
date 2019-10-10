/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:22:27 by aolen             #+#    #+#             */
/*   Updated: 2019/10/10 17:22:31 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

extern int errno;

void	print_errors(char *filename)
{
	if (errno == EACCES)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	if (errno == ENOENT)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
}