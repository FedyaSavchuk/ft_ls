/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:19:16 by aolen             #+#    #+#             */
/*   Updated: 2019/10/23 19:19:22 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include "Libft/libft.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef struct	p_flags
{
				int l;							// показывает расширенную информацию по фпйлам
				int a;							// показывает скрытые файлы и каталоги
				int R;							// рекурсивный просмотр всех файлов и каталогов в директории
				int r;							// вывод в обратном порядке
				int t;							// сортировка по времени
				int g;							// работает как -l, только не выводит создателя
				int A;
				int f;
				int S;
				int m;
				int s;
				int one;
}				l_flags;

l_flags *g_flags_ls;

typedef struct	l_file
{
				char			*chmod;			// fileStat.st_mode
				int				nlink;			// fileStat.st_nlink
				char			*user_name;		// pwd->pw_name
				char 			*group;
				char 			*date;
				int 			file_size;		// fileStat.st_size
				unsigned int	min;
				unsigned int	maj;
				char			*time;			// fileStat.st_mtimespec.tv_sec
				long			unix_time;		// время в формате юникод
				char			*file_name;		// dir -> d_name
				int 			st_blocks;		// количество блоков
				struct l_file 	*next;
}				l_file;

struct s_ls_vars
{
				unsigned int	total_blocks;
} g_ls_vars;

struct ls_sizes
{
				int				link_len;
				int				size_len;
				int				user_len;
				int				block_len;
				int				group_len;
				int				maj_len;
				int				minor_len;
};

int			complete_list(l_file *files, char *file_name);
l_file		**sort_by_ascii(l_file **struct_array);		// сортирует файлы и каталоги по ASCII
void		print_ls(l_file **struct_array, char *dir_name, int r_flag, int f);
l_file		**sort_by_time(l_file **struct_array);
l_file		**sort_by_size(l_file **struct_array);
char 		*ft_strjoin_safe(char **str1, const char *str2);
void		free_3ptr(DIR **ptr, struct dirent **dir, char **c);
char		*ft_strndup(const char *str, int n);
void		print_errors(char **filename, int r);
void		print_usage(char *argv0, char invalid_flag);
void 		print_directory(char *filename);
int			sort_args(l_file **dirs, l_file **files, int *size_d, int size_f);
l_file		*add_params_f(l_file *files, char **d_name, struct dirent *dir);
int			check_flags(int argc, char **argv);
int			int_len(int number);
int			max_len(l_file **struct_array, char column);
void		add_major_minor(struct stat file_stat, l_file *files);
void		add_chmod(l_file *files, char *d_name, struct dirent *dir);
void		add_chmod_files(l_file *files, char *d_name);


#endif
