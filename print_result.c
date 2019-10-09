
#include "ft_ls.h"
#include <stdio.h>

static int	int_len(int number)
{
	int count = (number == 0) ? 1 : 0;
	while (number)
	{
		count++;
		number /= 10;
	}
	return count;
}

static int	max_len(l_file **struct_array, char column)
{
	int 	i;
	int 	max_len;
	int 	len;

	max_len = 0;
	i = 0;
	while (struct_array[i])
	{
		if (column == 'l')
			len = int_len(struct_array[i]->nlink);
		if (column == 'f')
			len = int_len(struct_array[i]->file_size);
		if (max_len < len)
			max_len = len;
		i++;
	}
	return (max_len);
}

void	print_ls(l_file **struct_array, char *dir_name)
{
	int i;
	int n_link;
	int	size;

	i = -1;
	n_link = max_len(struct_array, 'l');
	size = max_len(struct_array, 'f');
	if (g_flags_ls->R && !ft_strequ(dir_name, "."))
		printf("\n%s:\n", dir_name);
	if (g_flags_ls->l)
		printf("total %d\n", struct_array[i + 1]->total);
	while (struct_array[++i])
	{
		if (!g_flags_ls->a && struct_array[i]->file_name[0] == '.')
			continue ;
		if (g_flags_ls->l)
		{
			printf("%-12s", struct_array[i]->chmod);
			printf("%*d", n_link, struct_array[i]->nlink);
			printf(" %s  ", struct_array[i]->user_name);
			printf("%.4s  ", struct_array[i]->year);
			printf("%*d ", size, struct_array[i]->file_size);
			printf("%s", struct_array[i]->month);
			printf("%3s ", struct_array[i]->day);
			printf("%.5s ", struct_array[i]->time);
		}
		printf("%s\n", struct_array[i]->file_name);
	}
}


