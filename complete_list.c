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
#define BUF_SIZE 1024
#include <sys/acl.h>

//static long ft_abs(long n)
//{
//	if (n < 0)
//		return (-n);
//	return (n);
//}

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
		if (last3bits & 4)
			chmod = ft_strcat(chmod, "r");
		else
			chmod = ft_strcat(chmod, "-");
		if (last3bits & 2)
			chmod = ft_strcat(chmod, "w");
		else
			chmod = ft_strcat(chmod, "-");
		if (last3bits & 1)
			chmod = ft_strcat(chmod, "x");
		else
			chmod = ft_strcat(chmod, "-");
		bits_move -= 3;
	}
	if(n & S_ISUID)
		chmod[3] = (chmod[3] == 'x') ? 's' : 'S';
	if(n & S_ISGID)
		chmod[6] = (chmod[6] == 'x') ? 's' : 'S';
	if(n & S_ISVTX)
		chmod[9] = (chmod[9] == 'x') ? 't' : 'T';
}

/*
** add_chmod_files
** --------------
** 	summary: add chmod params to file structure chmod param, from
**	fileStat.st_mode
**
**	files: address of file (d_name) structure
**	d_name: name of file or directory
*/

static l_file	*add_chmod_files(l_file *files, char *d_name)
{
	char			*chmod;
	struct stat		file_stat;
	char			s[BUF_SIZE];

	lstat(d_name, &file_stat);
	chmod = ft_strnew(12);
	if (S_ISLNK(file_stat.st_mode))
	{
		chmod = ft_strcat(chmod, "l");
		if (g_flags_ls->l || g_flags_ls->g)
		{
			files->file_name = ft_strjoin((files->file_name), " -> ");
			ft_bzero(s, BUF_SIZE);
			readlink(d_name, s, BUF_SIZE);
			files->file_name = ft_strjoin_safe(&(files->file_name), s);
		}
	}
	else if (S_ISREG(file_stat.st_mode))
		chmod = ft_strcat(chmod, "-");
	else if (S_ISDIR(file_stat.st_mode))
		chmod = ft_strcat(chmod, "d");
	else if (S_ISCHR(file_stat.st_mode))
		chmod = ft_strcat(chmod, "c");
	else if (S_ISBLK(file_stat.st_mode))
		chmod = ft_strcat(chmod, "b");
	else if (S_ISFIFO(file_stat.st_mode))
		chmod = ft_strcat(chmod, "p");
	else if (S_ISSOCK(file_stat.st_mode))
		chmod = ft_strcat(chmod, "s");
	fill_chmod(file_stat.st_mode, chmod);
	files->chmod = chmod;
	return (files);
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
	char			s[BUF_SIZE];

	if (dir == NULL)
		return add_chmod_files(files, d_name);
	lstat(d_name, &file_stat);
	chmod = ft_strnew(12);
	if (dir->d_type == DT_LNK)
	{
		chmod = ft_strcat(chmod, "l");
		if (g_flags_ls->l || g_flags_ls->g)
		{
			files->file_name = ft_strjoin(files->file_name, " -> ");
			ft_bzero(s, BUF_SIZE);
			readlink(d_name, s, BUF_SIZE);
			files->file_name = ft_strjoin_safe(&files->file_name, s);
		}
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
	else
		chmod = ft_strcat(chmod, "d");
	fill_chmod(file_stat.st_mode, chmod);
	files->chmod = chmod;
	return (files);
}

void add_major_minor(struct stat file_stat, l_file *files)
{
	if (S_ISCHR(file_stat.st_mode) || S_ISBLK(file_stat.st_mode)) {
		files->maj = major(file_stat.st_rdev);
		files->min = minor(file_stat.st_rdev);
	} else {
		files->maj = 0U;
		files->min = 0U;
	}
}

void	time_and_xattr(l_file *files, char **d_name)
{
	char	*date;
	int 	k;
	acl_t 			acl;

	k = 0;
	date = ctime(&files->unix_time);
	files->date = ft_strndup(&date[4], 7);
	if ((unsigned long)difftime(time(NULL), files->unix_time) < HALF_YEAR)
		files->time = ft_strndup(&date[11], 5);
	else
	{
		date = date + 20;
		while(*date == ' ')
			date++;
		while(*(date + k) != '\n')
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

l_file	*add_params_f(l_file *files, char **d_name, struct dirent *dir)
{
	struct stat		file_stat;
//	char			*date;
//	acl_t 			acl;

	lstat(*d_name, &file_stat);
	files->file_name = !files->file_name ? ft_strdup(dir->d_name) : files->file_name;
	add_chmod(files, *d_name, dir); /////
	files->unix_time = file_stat.st_mtimespec.tv_sec;
	time_and_xattr(files, d_name);
//	date = ctime(&files->unix_time);
//	files->date = ft_strndup(&date[4], 7);
//	files->time = (unsigned long)difftime(time(NULL), files->unix_time) < HALF_YEAR
//			? ft_strndup(&date[11], 5) :  ft_strndup(&date[20], 4);
	files->user_name = getpwuid(file_stat.st_uid)->pw_name;
	files->nlink = file_stat.st_nlink;
	files->file_size = file_stat.st_size;
	add_major_minor(file_stat, files);
	files->st_blocks = file_stat.st_blocks;
	files->group = getgrgid(file_stat.st_gid)->gr_name;
//	if (listxattr(*d_name, NULL, 0, XATTR_NOFOLLOW) > 0)
//		ft_strcat(files->chmod, "@");
//	else if ((acl = acl_get_link_np(*d_name, ACL_TYPE_EXTENDED)))
//	{
//		free(acl);
//		ft_strcat(files->chmod, "+");
//	}
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


int				complete_list(l_file *files, char *file_name)
{
	DIR				*ptr;
	struct dirent	*dir;
	l_file			*start_list;
	l_file			*new_elem;
	char			*temp;

	file_name = ft_strjoin(file_name, "/");
	start_list = files;
	if (!(ptr = opendir(file_name)))
//		add_params_f(files, &file_name, file_name);
		return (-1);
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
	return (0);
}
