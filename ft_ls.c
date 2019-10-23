#include "ft_ls.h"
#include <errno.h>
#define MAX_LEN 512

static int	check_flags(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' && argv[i][j + 1] != 0)
		{
			j++;
			while (argv[i][j])
			{
				if (argv[i][j] == 'l')
				{
					g_flags_ls->l = 1;
					g_flags_ls->one = 0;
				}
				else if (argv[i][j] == 'R')
					g_flags_ls->R = 1;
				else if (argv[i][j] == 'a')
				{
					g_flags_ls->a = 1;
					g_flags_ls->A = 0;
				}
				else if (argv[i][j] == 'r')
					g_flags_ls->r = 1;
				else if (argv[i][j] == 't')
					g_flags_ls->t = 1;
				else if (argv[i][j] == 'g')
				{
					g_flags_ls->g = 1;
					g_flags_ls->one = 0;
				}
				else if (argv[i][j] == 'A') ////
					g_flags_ls->A = g_flags_ls->a ? 0 : 1;
				else if (argv[i][j] == 'S') ////
					g_flags_ls->S = 1;
				else if (argv[i][j] == 'f') ////
					g_flags_ls->f = 1;
				else if (argv[i][j] == 'm') ///
					g_flags_ls->m = 1;
				else if (argv[i][j] == 's')
					g_flags_ls->s = 1;
				else if (argv[i][j] == '1' )
				{
					g_flags_ls->one = 1;
					g_flags_ls->g = 0;
					g_flags_ls->l = 0;
				}
				else if (argv[i][j] == '-' && j == 1 && argv[i][j + 1] == '\0')
					return (i + 1);
				else
					print_usage(argv[0], argv[i][j]);
				j++;
			}
		}
		else
			return (i);
		i++;
	}
	return (i);
}

static l_file 	**make_array(l_file *files)
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
	struct_array = (l_file **)malloc(sizeof(*struct_array) * i);
	i = 0;
	files = start;
	while (files)
	{
		struct_array[i] = (l_file *)malloc(sizeof(l_file*) * 1);
		struct_array[i] = files;
		files = files->next;
		i++;
	}
	struct_array[i - 1] = NULL;
	return (struct_array);
}

static l_file	**sort_list(l_file *files)
{
	l_file **struct_array;

	struct_array = make_array(files);
	if (!g_flags_ls->f)
		sort_by_ascii(struct_array);
	if (g_flags_ls->t && !g_flags_ls->f)
		sort_by_time(struct_array);
	if (g_flags_ls->S && !g_flags_ls->f)
		sort_by_size(struct_array);
	return (struct_array);
}

void			ft_ls(char *file_name, int r_flag)
{
	l_file *files;
	l_file **struct_array;
	int i;
	char *ptr;

	i = -1;
	files = (l_file *)malloc(sizeof(l_file) * 1);
	if (complete_list(files, file_name) < 0)
		return print_errors(&file_name, r_flag);
	struct_array = sort_list(files);
	print_ls(struct_array, file_name, r_flag, 0);
	while (struct_array[++i] && g_flags_ls->R)
	{
		if (struct_array[i]->chmod[0] =='d' && !(ft_strequ(struct_array[i]->file_name,".") ||
			ft_strequ(struct_array[i]->file_name,"..")))
		{
			if (!(g_flags_ls->A || g_flags_ls->a) && struct_array[i]->file_name[0] == '.')
				continue ;
			ptr = ft_strjoin(file_name, "/");
			ptr = ft_strjoin(ptr, struct_array[i]->file_name);
			ft_ls(ptr, 1);
			ft_strdel(&ptr);
		}
	}
	free(files);
}

int handle_args(l_file **dirs, l_file **files, int *argc, char **argv)
{
	int i;
	extern int	errno;
	int size_f;
	int size_d;
	char buf[512];

	i = check_flags(*argc, argv) - 1;;
	size_f = 0;
	size_d = 0;
	while (++i < *argc)
	{
		if (ft_strlen(argv[i]) < 1)
			print_errors(&argv[i], 0);
		if ((!(opendir(argv[i])) && errno == ENOTDIR ) ||
		((readlink(argv[i], buf, 512)) > 0 && (g_flags_ls->l || !opendir(argv[i]))))
		{
			files[size_f] = (l_file *) ft_memalloc(sizeof(l_file));
			files[size_f++]->file_name = argv[i];
			continue ;
		}
		dirs[size_d] = (l_file *)ft_memalloc(sizeof(l_file));
		dirs[size_d++]->file_name = argv[i];
	}
	 i =sort_args(dirs, files, &size_d, size_f);
	if (size_d == 0 && size_f == 0)
		ft_ls(".", 0);
	print_ls(files, NULL, 0, 1);
	if (g_flags_ls->m && size_f > 0)
		printf("\n\n");
	else if (size_d - i > 0 && size_f > 0)
		printf("\n");
	*argc = size_f;
	return size_d;
}

int 	main(int argc, char **argv)
{
	int			i;
	static l_file	*files[MAX_LEN] = {NULL};
	static l_file	*dirs[MAX_LEN] = {NULL};
	int			j;

	g_flags_ls = (l_flags *)malloc(sizeof(l_flags) * 1);
	ft_bzero(g_flags_ls, sizeof(l_flags));
//	while (++i < argc)
//	{
//		dirs[j] = (l_file *)ft_memalloc(sizeof(l_file) * 1);
//		if ((opendir(argv[i])))
//			dirs[j++]->file_name = argv[i];
//		else if (errno == ENOTDIR)
//	}
	j = handle_args(dirs, files, &argc, argv);
	i = -1;
//	i = -1;
//	if (j == 0)
//		ft_ls(".", 0);
//	else
//		while (dirs[++i])
//			if (!opendir(dirs[i]->file_name))
//			{
//				if (errno == ENOENT)
//					print_errors(&dirs[i]->file_name);
//				else
//				{
//					*files = dirs[i];
//					(*files)++;
//				}
//			}
//	sort_agrs(dirs, j);
	while (++i < j)
		if (dirs[i] && dirs[i]->file_name[0])
		{
			if (j + argc > 1)
				print_directory(dirs[i]->file_name);
			ft_ls(dirs[i]->file_name, 0);
			if (dirs[i + 1] && dirs[i + 1]->file_name)
				printf("\n");
		}
	return (errno != 0 ? 1 : 0);
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

