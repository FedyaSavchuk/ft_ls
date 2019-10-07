
#include "ft_ls.h"

static l_file	*add_chmod(l_file *files, struct dirent *dir)
{
	char		*s;
	char		*chmod;
	struct stat fileStat;
	int 		i;

	i = 1;
	stat(dir->d_name, &fileStat);
	chmod = (char *)malloc(sizeof(char));
	if (S_ISREG(fileStat.st_mode))
		chmod = ft_strjoin(chmod, "-");
	if (S_ISDIR(fileStat.st_mode))
		chmod = ft_strjoin(chmod, "d");
	if (S_ISLNK(fileStat.st_mode))
		chmod = ft_strjoin(chmod, "x");
	s = ft_itoa_base(fileStat.st_mode, 8, 'a');
	while (i++ < 4)
	{
		if (s[i] == '0')
			chmod = ft_strjoin(chmod, "---");
		if (s[i] == '1')
			chmod = ft_strjoin(chmod, "--x");
		if (s[i] == '2')
			chmod = ft_strjoin(chmod, "-w-");
		if (s[i] == '3')
			chmod = ft_strjoin(chmod, "-wx");
		if (s[i] == '4')
			chmod = ft_strjoin(chmod, "r--");
		if (s[i] == '5')
			chmod = ft_strjoin(chmod, "r-x");
		if (s[i] == '6')
			chmod = ft_strjoin(chmod, "rw-");
		if (s[i] == '7')
			chmod = ft_strjoin(chmod, "rwx");
	}
	files->chmod = chmod;
	return (files);
}

static l_file	*add_time(l_file *files, struct dirent *dir)
{
	struct	stat fileStat;
	char	**words;

	stat(dir->d_name, &fileStat);
	words = ft_strsplit(ctime(&fileStat.st_mtimespec.tv_sec), ' ');
	files->month = words[1];
	files->day = words[2];
	files->time = words[3];
	files->year = words[4];
	return (files);
}

static l_file	*add_stat(l_file *files, struct dirent *dir)
{
	struct stat		fileStat;
	struct passwd	*pwd;

	stat(dir->d_name, &fileStat);
	pwd = getpwuid(fileStat.st_uid);
	files->user_name = pwd->pw_name;
	files->nlink = fileStat.st_nlink;
	files->file_size = fileStat.st_size;
	files->st_blocks = fileStat.st_blocks;
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

l_file			*complete_list(l_file *files)
{
	DIR		*ptr;  //указатель на поток
	struct	dirent *dir;
	l_file	*start_list;
	l_file	*new_elem;

	start_list = files;
	ptr = opendir(".");
	dir = readdir(ptr);
	while (dir)
	{
		clear_list(files);
		files->file_name = dir->d_name;
		add_chmod(files, dir);
		add_time(files, dir);
		add_stat(files, dir);
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
