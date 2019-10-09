#ifndef LS
#define LS
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
}				l_flags;

l_flags *g_flags_ls;

typedef struct	l_file
{
				int 			total;			// сумма блоков (fileStat.st_blocks)
				char			*chmod;			// fileStat.st_mode
				int				nlink;			// fileStat.st_nlink
				char			*user_name;		// pwd->pw_name
				char 			*group;
				char			*year;			// fileStat.st_mtimespec.tv_sec
				int 			file_size;		// fileStat.st_size
				char 			*month;			// fileStat.st_mtimespec.tv_sec
				char			*day;			// fileStat.st_mtimespec.tv_sec
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

char		*ft_itoa_base(long long int nbr, int base, char reg);	// для разрешений (chmod)
l_file		*complete_list(l_file *files, char *file_name);
void		clear_list(l_file *files);
l_file		**sort_by_ascii(l_file **struct_array);		// сортирует файлы и каталоги по ASCII
void		print_ls(l_file **struct_array, char *dir_name);
l_file		**sort_by_time(l_file **struct_array);
l_file		**sort_by_size(l_file **struct_array);
char		*ft_strjoin_safe(char *str1, const char *str2);


#endif

