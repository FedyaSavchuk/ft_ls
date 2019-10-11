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

void	sort_agrs(char **argv, int size)
{
	int i;
	int j;
	int r;
	char *temp;

	if (size < 2)
		return ;
	r = g_flags_ls->r ? -1 : 1;
	i = 2;
	while (i < size)
	{
		j = i - 1;
		temp = argv[i];
		while (j >= 1 && r * ft_strcmp(argv[j], temp) < 0)
		{
			argv[j + 1] = argv[j];
			j--;
		}
		argv[j + 1] = temp;
		i++;
	}
}