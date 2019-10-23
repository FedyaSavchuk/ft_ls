/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:25:52 by aolen             #+#    #+#             */
/*   Updated: 2019/10/09 18:25:56 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

l_file		**sort_by_ascii(l_file **struct_array)
{
	int		i;
	int		j;
	int		r;
	l_file	*temp;

	r = g_flags_ls->r ? -1 : 1;
	i = 1;
	while (struct_array[i])
	{
		j = i - 1;
		temp = struct_array[i];
		while (j >= 0 && r * ft_strcmp(struct_array[j]->file_name,
				temp->file_name) > 0)
		{
			struct_array[j + 1] = struct_array[j];
			j--;
		}
		struct_array[j + 1] = temp;
		i++;
	}
	return (struct_array);
}

l_file		**sort_by_time(l_file **struct_array)
{
	int		i;
	int		j;
	int		r;
	l_file	*temp;

	r = g_flags_ls->r ? -1 : 1;
	i = 1;
	while (struct_array[i])
	{
		j = i - 1;
		temp = struct_array[i];
		while (j >= 0 && r * (struct_array[j]->unix_time - temp->unix_time) < 0)
		{
			struct_array[j + 1] = struct_array[j];
			j--;
		}
		struct_array[j + 1] = temp;
		i++;
	}
	return (struct_array);
}

l_file		**sort_by_size(l_file **struct_array)
{
	int		i;
	int		j;
	int		r;
	l_file	*temp;

	r = g_flags_ls->r ? -1 : 1;
	i = 1;
	while (struct_array[i])
	{
		j = i - 1;
		temp = struct_array[i];
		while (j >= 0 && r * (struct_array[j]->file_size - temp->file_size) < 0)
		{
			struct_array[j + 1] = struct_array[j];
			j--;
		}
		struct_array[j + 1] = temp;
		i++;
	}
	return (struct_array);
}

//void	sort_agrs_by_time(l_file **argv, int size)
//{
//	struct stat	file_stat;
//	int			i;
//	int 		j;
//	int			flag;
//	l_file		*temp;
//
//	i = -1;
//	while (++i < size)
//	{
//		lstat(argv[i]->file_name, &file_stat);
//		argv[i]->unix_time = file_stat.st_mtimespec.tv_sec;
//	}
//	i = -1;
//	while (++i < size)
//	{
//		j = 0;
//		flag = 0;
//		while (++j < size)
//		{
//			if (argv[j - 1]->unix_time > argv[j]->unix_time)
//				flag = 1;
//			temp = argv[j - 1];
//			argv[j - 1] = argv[j];
//			argv[j] = temp;
//		}
//		if (flag)
//			i = -1;
//	}
//}

//void	sort_agrs(l_file **argv, int size)
//{
//	int i;
//	int j;
//	int r;
//	char *temp;
//
//	if (size < 2 || g_flags_ls->f)
//		return ;
//	r = g_flags_ls->r ? -1 : 1;
//	i = 1;
//	while (i < size)
//	{
//		j = i - 1;
//		temp = argv[i]->file_name;
//		while (j >= 0 && r * ft_strcmp(argv[j]->file_name, temp) < 0)
//		{
//			argv[j + 1]->file_name = argv[j]->file_name;
//			j--;
//		}
//		argv[j + 1]->file_name = temp;
//		i++;
//	}
//	if (g_flags_ls->t)
//		sort_agrs_by_time(argv, size);
//}