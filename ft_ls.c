#include "ft_ls.h"
#define MAX_LEN 256

void	clear_flags()
{
	g_flags_ls->l = 0;
	g_flags_ls->a = 0;
	g_flags_ls->R = 0;
	g_flags_ls->r = 0;
	g_flags_ls->t = 0;
}

void		clear_list(l_file *files)
{
	files->total = 0;
	files->chmod = NULL;
	files->nlink = 0;
	files->user_name = NULL;
	files->year = NULL;
	files->file_size = 0;
	files->month = NULL;
	files->day = NULL;
	files->time = NULL;
	files->file_name = NULL;
	files->next = NULL;
	files->st_blocks = 0;
}

void	check_flags(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] != '-')
			return ;
		else if (argv[i][j] == '-')
		{
			while (argv[i][j])
			{
				if (argv[i][j] == 'l')
					g_flags_ls->l = 1;
				else if (argv[i][j] == 'R')
					g_flags_ls->R = 1;
				else if (argv[i][j] == 'a')
					g_flags_ls->a = 1;
				else if (argv[i][j] == 'r')
					g_flags_ls->r = 1;
				else if (argv[i][j] == 't')
					g_flags_ls->t = 1;
				j++;
			}
		}
		i++;
	}
}

//void	check_flags(int argc, char **argv)
//{
//	int i;
//	int j;
//
//	i = 1;
//	while (i < argc && argv[i][j] == '-')
//	{
//		j = 0;
//		while (argv[i][j])
//		{
//			if (argv[i][j] == 'l')
//				g_flags_ls->l = 1;
//			else if (argv[i][j] == 'R')
//				g_flags_ls->R = 1;
//			else if (argv[i][j] == 'a')
//				g_flags_ls->a = 1;
//			else if (argv[i][j] == 'r')
//				g_flags_ls->r = 1;
//			else if (argv[i][j] == 't')
//				g_flags_ls->t = 1;
//			j++;
//		}
//		i++;
//	}
//}

l_file 	**make_array(l_file *files)
{
	l_file **struct_array;
	l_file *start;
	int i;

	i = 0;
	start = files;
	while (files)
	{
		i++;
		files = files->next;
	}
	struct_array = (l_file **)malloc(sizeof(l_file) * i);
	i = 0;
	files = start;
	while (files)
	{
		struct_array[i] = (l_file *)malloc(sizeof(l_file) * 1);
		struct_array[i] = files;
		files = files->next;
		i++;
	}
	struct_array[i - 1] = NULL;
	return (struct_array);
}

void	ft_ls(char *file_name)
{
	l_file *files;
	l_file **struct_array;
	int i;
	char *ptr;
	char *temp;

	i = -1;
	files = (l_file *)malloc(sizeof(l_file) * 1);
	complete_list(files, file_name);
	struct_array = make_array(files);
	sort_by_ascii(struct_array);
	print_ls(struct_array, file_name);
	while (struct_array[++i] && g_flags_ls->R)
	{
		if (struct_array[i]->chmod[0] =='d' && !(ft_strequ(struct_array[i]->file_name,".") ||
			ft_strequ(struct_array[i]->file_name,"..")))
		{
			ptr = ft_strjoin(file_name, "/");
			temp = ptr;
			ptr = ft_strjoin(ptr, struct_array[i]->file_name);
			ft_ls(ptr);
			ft_strdel(&ptr);
			ft_strdel(&temp);
		}
	}
	free(files);
}

int 	main(int argc, char **argv)
{
	int			i;
	static char	*dirs[MAX_LEN] = {NULL};
	int			j;

	i = 0;
	j = 0;
	g_flags_ls = (l_flags *)malloc(sizeof(l_flags) * 1);
	clear_flags();
	check_flags(argc, argv);
	while (++i < argc)
		if (argv[i][0] != '-')
			dirs[j++] = argv[i];
	i = -1;
	if (j == 0)
		ft_ls(".");
	else
		while (dirs[++i])
			ft_ls(dirs[i]);
	return (0);
}

//	clear_flags();
//	complete_list(files);
//	struct_array = make_array(files);
//	sort_by_ascii(struct_array);
//	print_ls(struct_array)















//	print_ls(files);

//	write(1, "Check Flags\n", 12);
//	write(1, files->chmod, 12);
//	ft_putnbr(files->nlink);
//	write(1, files->user_name, 8);
//	write(1, files->year, 4);
//	ft_putnbr(files->file_size);
//	ft_putnbr(struct_array[0]->total);
//	write(1, files->month, 3);
//	write(1, files->day, 2);
//	write(1, files->time, 8);
//	write(1, files->file_name, 6);
//	write(1, files->year, 12);



//	char list;
////	int x;
////	x = listxattr("/Users/hspeeder/Desktop/School_42/Ft_ls", &list, 10000000, XATTR_NOFOLLOW);


//	printf("%d", x);

//	//// opendir / readdir
//	DIR *ptr;  //указатель на поток
//	struct dirent *dir;
//
//	ptr = opendir("a.out");
//	dir = readdir(ptr);
//	printf("%s", dir->d_name); 			// имя файла
//	printf("%hhu", dir->d_type); 		// 8 - файл, 4 - папка
//	printf("\n%llu", dir->d_seekoff); 	// позиция файла по порядку
//	printf("\n%hu", dir->d_reclen);		// размер файла в байтах
//	printf("\n%hu", dir->d_namlen); 		// длина имени файла
//	printf("\n%llu", dir->d_ino);			// индекс файла в файловой системе unix
//
//
//	//// stat / lstat (link stat - для символьных ссылок)
//	struct stat fileStat;
//	stat("a.out", &fileStat);

//	printf("%d", fileStat.st_nlink);			// количество жестких ссылок на файл
//	printf("\n%d", fileStat.st_uid);			// id владельца файла
//	printf("\n%ld\n", fileStat.st_birthtimespec.tv_sec);
//	printf("\n%ld", fileStat.st_birthtimespec.tv_nsec);
//	printf("\n%d", fileStat.st_gen);
//	printf("%ld\n", fileStat.st_atimespec.tv_sec);
//	printf("\n%d", fileStat.st_mode);		// 16877 (последние 3 числа - это права доступа), а первые 2 - обозначают тип файла
//	printf("\n%d", fileStat.st_gid);			// групповой id владельцев файлов
//	printf("\n%lld", fileStat.st_size);		// размер файла в байтах
//	printf("\n%d", fileStat.st_blksize);		// оптимальный размер блока
//	printf("\n%lld", fileStat.st_blocks);	// количество отведенных блоков (по 512 байт)
//	printf("\n%ld\n", fileStat.st_ctimespec.tv_sec);
//	printf("\n%d", fileStat.st_dev);			// идентификатор устройства, на котором находится файл
//	printf("\n%d", fileStat.st_flags);
//	printf("\n%llu", fileStat.st_ino);			// индекс файла в файловой системе unix
//	printf("\n%d", fileStat.st_lspare);
//	printf("\n%ld\n", fileStat.st_mtimespec.tv_sec);
//	printf("%s", ctime(&fileStat.st_mtimespec.tv_sec));
//	printf("\n%ld", fileStat.st_qspare);
//	printf("\n%d", fileStat.st_rdev);		// тип устройства
//
//
//	//// getpwuid
//	struct passwd *pwd;
//	pwd = getpwuid(fileStat.st_uid);
//	printf("\n%s", pwd->pw_name);				// имя пользователя
//	printf("\n%s", pwd->pw_passwd);				// зашифрованный пароль пользователя
//	printf("\n%s", pwd->pw_shell);				// оболочка входа в систему
//	printf("\n%d", pwd->pw_uid);				// id владельца файла
////	printf("\n%d", pwd->pw_gid);				// групповой id владельцев файлов
//	printf("\n%s", pwd->pw_gecos);				// комментарий (обычно полное имя пользователя)
//	printf("\n%s", pwd->pw_dir);				// домашний каталог
//
//
//	//// getgrgid
//	struct group *gwd;
//	gwd = getgrgid(fileStat.st_gid);
//	printf("\n\n\n%s", gwd->gr_name);
//	printf("\n%d", gwd->gr_gid);
//	printf("\n%s", gwd->gr_passwd);
//
//
//	//// listxattr
//	char 	list;
//	ssize_t  count;
//	count = listxattr("..", &list, 10000, XATTR_SHOWCOMPRESSION);
//	printf("\n%zu", count);

