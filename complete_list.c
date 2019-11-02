/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:50:19 by aolen             #+#    #+#             */
/*   Updated: 2019/10/09 11:50:21 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"
#define HALF_YEAR 2629743 * 6
#include <sys/acl.h>

/*
** safe_opendir
** --------------
** 	summary: if dir can be opened return 1 and free ptr
**
**	d_name: string with filename
*/

int			safe_opendir(char *d_name)
{
	DIR				*ptr;

	ptr = opendir(d_name);
	if (ptr)
	{
		closedir(ptr);
		return (1);
	}
	return (0);
}

/*
** time_and_xattr
** --------------
** 	summary: add time (hours:minutes or year) and xattr if file has it
**
**	files: address of file (d_name) structure
**	d_name: pointer to string with filename
*/

static void	time_and_xattr(t_file *files, char **d_name)
{
	char	*date;
	int		k;
	acl_t	acl;

	k = 0;
	date = ctime(&files->unix_time);
	files->date = ft_strndup(&date[4], 7);
	if ((unsigned long)(time(NULL) - files->unix_time) < HALF_YEAR)
		files->time = ft_strndup(&date[11], 5);
	else
	{
		date = date + 20;
		while (*date == ' ')
			date++;
		while (*(date + k) != '\n')
			k++;
		files->time = ft_strndup(date - 1, k + 1);
	}
	if (listxattr(*d_name, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_strcat(files->chmod, "@");
	else if ((acl = acl_get_link_np(*d_name, ACL_TYPE_EXTENDED)))
	{
		free(acl);
		ft_strcat(files->chmod, "+");
	}
}

/*
** add_params
** --------------
** 	summary: add params to file structure, list of params:
**		time,
**		user_name,
**		number of hard links,
**		size of file,
**		number of blocks
**	after adding free string with file name
**
**	files: address of file (d_name) structure
**	d_name: name of file or directory
*/

t_file		*add_params_f(t_file *files, char **d_name, struct dirent *dir)
{
	struct stat		file_stat;

	lstat(*d_name, &file_stat);
	files->file_name = !files->file_name ? ft_strdup(dir->d_name) :
			files->file_name;
	if (dir == NULL)
		add_chmod_files(files, *d_name);
	else
		add_chmod(files, *d_name, dir);
	files->unix_time = file_stat.st_mtimespec.tv_sec;
	time_and_xattr(files, d_name);
	files->user_name = getpwuid(file_stat.st_uid)->pw_name;
	files->nlink = file_stat.st_nlink;
	files->file_size = file_stat.st_size;
	add_major_minor(file_stat, files);
	files->st_blocks = file_stat.st_blocks;
	files->group = getgrgid(file_stat.st_gid)->gr_name;
	ft_strdel(dir ? d_name : NULL);
	return (files);
}

/*
** add_total
** --------------
** 	summary: count sum of memory blocks for all file (if -a flag used)
**	and only for visible files (if there is no -a flag)
**
**	start_list: start address of file list (d_name) structures
*/

static void	add_total(t_file *start_list)
{
	int		total;
	t_file	*start;

	start = start_list;
	total = 0;
	while (start_list->next)
	{
		if (!(g_flags_ls->a) && !(g_flags_ls->a_cap)
			&& start_list->file_name[0] == '.')
		{
			start_list = start_list->next;
			continue ;
		}
		if ((g_flags_ls->a_cap) && start_list->chmod[0] == 'd' &&
			(ft_strequ(start_list->file_name, ".") ||
			ft_strequ(start_list->file_name, "..")))
		{
			start_list = start_list->next;
			continue ;
		}
		total = total + start_list->st_blocks;
		start_list = start_list->next;
	}
	start_list = start;
	g_ls_vars.total_blocks = total;
}

/*
** complete_list
** --------------
** 	summary: fills the list of files structures with data from stat structures
**	in current dir (file_name)
**
**	files: start address of file list (d_name) structures
**	file_name: name of directory that will be opened
*/

int			complete_list(t_file *files, char *file_name)
{
	DIR				*ptr;
	struct dirent	*dir;
	t_file			*start_list;
	t_file			*new_elem;
	char			*temp;

	file_name = ft_strjoin(file_name, "/");
	start_list = files;
	if (!(ptr = opendir(file_name)))
		return (-1);
	dir = readdir(ptr);
	while (dir)
	{
		temp = ft_strjoin(file_name, dir->d_name);
		add_params_f(files, &temp, dir);
		new_elem = (t_file *)ft_memalloc(sizeof(t_file));
		files->next = new_elem;
		files = files->next;
		dir = readdir(ptr);
	}
	files->next = NULL;
	add_total(start_list);
	free_3ptr(&ptr, &dir, &file_name, &temp);
	return (0);
}
