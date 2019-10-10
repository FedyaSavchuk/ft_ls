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
#define ELDER_BITS 261632
#define BUF_SIZE 256

/*
** fill_chmod
** --------------
** 	summary: fills the empty string
**
**	files: address of file (d_name) structure
**	d_name: name of file or directory
*/

static void		fill_chmod(int n, char *chmod)
{
	char	last3bits;
	int		bits_move;

	bits_move = 6;
	while (bits_move >= 0)
	{
		last3bits = (n >> bits_move) & 7;
		if (last3bits == 0)
			chmod = ft_strcat(chmod, "---");
		else if (last3bits == 1)
			chmod = ft_strcat(chmod, "--x");
		else if (last3bits == 2)
			chmod = ft_strcat(chmod, "-w-");
		else if (last3bits == 3)
			chmod = ft_strcat(chmod, "-wx");
		else if (last3bits == 4)
			chmod = ft_strcat(chmod, "r--");
		else if (last3bits == 5)
			chmod = ft_strcat(chmod, "r-x");
		else if (last3bits == 6)
			chmod = ft_strcat(chmod, "rw-");
		else if (last3bits == 7)
			chmod = ft_strcat(chmod, "rwx");
		bits_move -= 3;
	}
}

/*
** add_chmod
** --------------
** 	summary: add chmod params to file structure chmod param, from
**	fileStat.st_mode
**
**	files: address of file (d_name) structure
**	d_name: name of file or directory
*/

static l_file	*add_chmod(l_file *files, char *d_name, struct dirent *dir)
{
	char			*chmod;
	struct stat		file_stat;
	//char			s[BUF_SIZE];

	lstat(d_name, &file_stat);
	chmod = ft_strnew(12);
	if (dir->d_type == DT_LNK)
	{
		chmod = ft_strcat(chmod, "l");
//		if (g_flags_ls->l)
//		{
//			files->file_name = ft_strjoin(files->file_name, " -> ");
//			readlink(d_name, s, BUF_SIZE);
//			files->file_name = ft_strjoin_safe(files->file_name, s);
//		}
	}
	else if (dir->d_type == DT_REG)
		chmod = ft_strcat(chmod, "-");
	else if (dir->d_type == DT_DIR)
		chmod = ft_strcat(chmod, "d");
	else if (dir->d_type == DT_CHR)
		chmod = ft_strcat(chmod, "c");
	else if (dir->d_type == DT_BLK)
		chmod = ft_strcat(chmod, "b");
	else if (dir->d_type == DT_FIFO)
		chmod = ft_strcat(chmod, "p");
	else if (dir->d_type == DT_SOCK)
		chmod = ft_strcat(chmod, "s");
	fill_chmod(file_stat.st_mode, chmod);
	files->chmod = chmod;
	return (files);
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

static l_file	*add_params_f(l_file *files, char **d_name, struct dirent *dir)
{
	struct stat		file_stat;
	char			*date;

	lstat(*d_name, &file_stat);
	files->file_name = dir->d_name;
	printf("%s\n", files->file_name);
	add_chmod(files, *d_name, dir);
	files->unix_time = file_stat.st_mtimespec.tv_sec;
	date = ctime(&files->unix_time);
	files->date = ft_strndup(&date[4], 7);
	files->time = (long int)difftime(time(NULL), files->unix_time) <= HALF_YEAR
			? ft_strndup(&date[11], 5) : ft_strndup(&date[20], 4);
	files->user_name = getpwuid(file_stat.st_uid)->pw_name;
	files->nlink = file_stat.st_nlink;
	files->file_size = file_stat.st_size;
	files->st_blocks = file_stat.st_blocks;
	files->group = getgrgid(file_stat.st_gid)->gr_name;
	ft_strdel(d_name);
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

static void		add_total(l_file *start_list)
{
	int		total;
	l_file	*start;

	start = start_list;
	total = 0;
	while (start_list->next)
	{
		if (!(g_flags_ls->a) && !(g_flags_ls->A)
			&& start_list->file_name[0] == '.')
		{
			start_list = start_list->next;
			continue ;
		}
		if ((g_flags_ls->A) && start_list->chmod[0] == 'd' &&
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

l_file			*complete_list(l_file *files, char *file_name)
{
	DIR				*ptr;
	struct dirent	*dir;
	l_file			*start_list;
	l_file			*new_elem;
	char			*temp;

	file_name = ft_strjoin(file_name, "/");
	start_list = files;
	ptr = opendir(file_name);
	dir = readdir(ptr);
	while (dir)
	{
		temp = ft_strjoin(file_name, dir->d_name);
		ft_bzero(files, sizeof(l_file));
		add_params_f(files, &temp, dir);
		new_elem = (l_file *)malloc(sizeof(l_file));
		files->next = new_elem;
		files = files->next;
		dir = readdir(ptr);
		ft_strdel(&temp);
	}
	files->next = NULL;
	add_total(start_list);
	free_3ptr(&ptr, &dir, &file_name);
	return (start_list);
}
