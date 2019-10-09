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


//static void		choose_chmod(int n, char *str)
//{
//	int i;
//	char last3bits;
//
//	i = 3;
//	while (i--)
//	{
//		last3bits = n & 7;
//		n = n >> 3;
//		if (last3bits == 0)
//			chmod = ft_strjoin(chmod, "---");
//		if (last3bits == 1)
//			chmod = ft_strjoin(chmod, "--x");
//		if (last3bits == 2)
//			chmod = ft_strjoin(chmod, "-w-");
//		if (last3bits == 3)
//			chmod = ft_strjoin(chmod, "-wx");
//		if (last3bits == 4)
//			chmod = ft_strjoin(chmod, "r--");
//		if (last3bits == 5)
//			chmod = ft_strjoin(chmod, "r-x");
//		if (last3bits == 6)
//			chmod = ft_strjoin(chmod, "rw-");
//		if (last3bits == 7)
//			chmod = ft_strjoin(chmod, "rwx");
//	}
//}

static l_file	*add_chmod(l_file *files, char *d_name)//struct dirent *dir)
{
	unsigned int	s;
	char			*chmod;
	struct stat 	fileStat;
	int 			i;

	stat(d_name, &fileStat);
	chmod = ft_strnew(12);
	if (S_ISREG(fileStat.st_mode))
		chmod = ft_strcat(chmod, "-");
	else if (S_ISDIR(fileStat.st_mode))
		chmod = ft_strcat(chmod, "d");
	else if (S_ISLNK(fileStat.st_mode))
		chmod = ft_strcat(chmod, "x");
	//choose_chmod(fileStat.st_mode);
	s = ft_atoi(ft_itoa_base(fileStat.st_mode, 8, 'a')) % 1000;
	i = 100;
	while (i != 0)
	{
		if (s / i % 10 == 0)
			chmod = ft_strcat(chmod, "---");
		if (s / i % 10 == 1)
			chmod = ft_strcat(chmod, "--x");
		if (s / i % 10 == 2)
			chmod = ft_strcat(chmod, "-w-");
		if (s / i % 10 == 3)
			chmod = ft_strcat(chmod, "-wx");
		if (s / i % 10 == 4)
			chmod = ft_strcat(chmod, "r--");
		if (s / i % 10 == 5)
			chmod = ft_strcat(chmod, "r-x");
		if (s / i % 10 == 6)
			chmod = ft_strcat(chmod, "rw-");
		if (s / i % 10 == 7)
			chmod = ft_strcat(chmod, "rwx");
		i /= 10;
	}
	chmod[10] = 0;
	files->chmod = chmod;
	return (files);
}

static l_file	*add_time(l_file *files, char *d_name)//struct dirent *dir)
{
	struct	stat fileStat;
	char	**words;

	stat(d_name, &fileStat);
	words = ft_strsplit(ctime(&fileStat.st_mtimespec.tv_sec), ' ');
	files->month = words[1];
	files->day = words[2];
	files->time = words[3];
	files->year = words[4];
	ft_strdel(&d_name);
	return (files);
}

static l_file	*add_stat(l_file *files, char *d_name)
{
	struct stat		fileStat;
	struct passwd	*pwd;

	stat(d_name, &fileStat);
	pwd = getpwuid(fileStat.st_uid);
	files->user_name = pwd->pw_name;
	files->nlink = fileStat.st_nlink;
	files->file_size = fileStat.st_size;
	files->st_blocks = fileStat.st_blocks;
	ft_strdel(&d_name);
	return(files);
}

static l_file	*add_total(l_file *files)
{
	int total;
	l_file *start;

	start = files;
	total = 0;
	while (files->next)
	{
		if (!(g_flags_ls->a) && files->file_name[0] == '.')
		{
			files = files->next;
			continue ;
		}
		total = total + files->st_blocks;
		files = files->next;
	}
	files = start;
	while (files->next)
	{
		files->total = total;
		files = files->next;
	}
	return (files);
}

l_file			*complete_list(l_file *files, char *file_name)
{
	DIR		*ptr;  //указатель на поток
	struct	dirent *dir;
	l_file	*start_list;
	l_file	*new_elem;

	start_list = files;
	ptr = opendir(file_name);
	dir = readdir(ptr);
	file_name = ft_strjoin(file_name, "/");
	while (dir)
	{
		clear_list(files);
		files->file_name = dir->d_name;
		add_chmod(files, ft_strjoin(file_name, dir->d_name));
		add_time(files, ft_strjoin(file_name, dir->d_name));
		add_stat(files, ft_strjoin(file_name, dir->d_name));
		new_elem = (l_file *)malloc(sizeof(l_file) * 1);
		files->next = new_elem;
		files = files->next;
		dir = readdir(ptr);
	}
	files->next = NULL;
	files = start_list;
	add_total(files);
	files = start_list;
	return (files);
}
