/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:27:26 by aolen             #+#    #+#             */
/*   Updated: 2019/10/09 20:27:26 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_3ptr(DIR **ptr, struct dirent **dir, char **c)
{
	free(*ptr);
	free(*dir);
	free(*c);
}

int			int_len(int number)
{
	int	count;

	count = (number == 0) ? 1 : 0;
	while (number)
	{
		count++;
		number /= 10;
	}
	return (count);
}

static void	search_max_len(l_file *struct_el, char column, int *max_len)
{
	int len;

	len = 0;
	if (column == 'l')
		len = int_len(struct_el->nlink);
	else if (column == 'f')
		len = int_len(struct_el->file_size);
	else if (column == 'u')
		len = ft_strlen(struct_el->user_name);
	else if (column == 'g')
		len = ft_strlen(struct_el->group);
	else if (column == 'b')
		len = int_len(struct_el->st_blocks);
	else if (column == 'm')
		len = int_len(struct_el->maj);
	else if (column == 'i')
		len = int_len(struct_el->min);
	if (*max_len < len)
		*max_len = len;
}

int			max_len(l_file **struct_array, char column)
{
	int		i;
	int		max_len;

	max_len = 0;
	i = -1;
	while (struct_array[++i])
	{
		if ((!g_flags_ls->a && !g_flags_ls->f) &&
			struct_array[i]->file_name[0] == '.')
			continue ;
		else
			search_max_len(struct_array[i], column, &max_len);
	}
	return (max_len);
}
