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

void	print_errors(char **filename)
{
	if (errno == EACCES)
	{
		ft_putendl("");
		print_directory(*filename);
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(&(*filename)[2], 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	if (errno == ENOENT)
	{
		ft_putstr_fd("ls: ", 2);
		*filename = ((*filename)[1] == '/') ? &(*filename)[2] : *filename;
		ft_putstr_fd(*filename, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		*filename = "";
	}
}

void	print_usage(char *argv0, char invalid_flag)
{
	ft_putstr_fd(argv0, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd(invalid_flag, 2);
	ft_putstr_fd("\n", 2);
	ft_putendl_fd("usage: ls [-ARSafglmrst1] [file ...]", 2);
	exit(1);
}