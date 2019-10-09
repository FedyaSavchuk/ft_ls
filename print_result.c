
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
	len = 0;
	i = -1;
	while (struct_array[++i])
	{
		if (!g_flags_ls->a && struct_array[i]->file_name[0] == '.')
			continue ;
		if (column == 'l')
			len = int_len(struct_array[i]->nlink);
		else if (column == 'f')
			len = int_len(struct_array[i]->file_size);
		else if (column == 'u')
			len = ft_strlen(struct_array[i]->user_name);
		else if (column == 'g')
			len = ft_strlen(struct_array[i]->group);
		else if (column == 'b')
			len = int_len(struct_array[i]->st_blocks);
		if (max_len < len)
			max_len = len;
	}
	return (max_len);
}

void	print_ls(l_file **struct_array, char *dir_name)
{
	int i;
	int link_len;
	int	size_len;
	int user_len;
	int block_len;

	i = -1;
	link_len = max_len(struct_array, 'l');
	size_len = max_len(struct_array, 'f');
	user_len = max_len(struct_array, 'u');
	block_len = max_len(struct_array, 'b');
	if (g_flags_ls->R && !ft_strequ(dir_name, "."))
		printf("\n%s:\n", dir_name);
	if (g_flags_ls->l)
		printf("total %d\n", g_ls_vars.total_blocks);
	while (struct_array[++i])
	{
		if (!g_flags_ls->a && !g_flags_ls->f && !g_flags_ls->A && struct_array[i]->file_name[0] == '.')
			continue ;
		if (g_flags_ls->A && struct_array[i]->chmod[0] == 'd' &&
			(!ft_strcmp((const char *)struct_array[i]->file_name, ".")
			|| !ft_strcmp((const char *)struct_array[i]->file_name, "..")))
			continue ;
		if ((g_flags_ls->l && !g_flags_ls->m) || (g_flags_ls->g && !g_flags_ls->m))
		{
			if (g_flags_ls->s)
				printf("%*d ", block_len, struct_array[i]->st_blocks);
			printf("%-12s", struct_array[i]->chmod);
			printf("%*d ", link_len, struct_array[i]->nlink);
			if (!(g_flags_ls->g))
				printf("%*s  ", user_len, struct_array[i]->user_name);
			printf("%.*s  ", max_len(struct_array, 'g'), struct_array[i]->group);
			printf("%*d ", size_len, struct_array[i]->file_size);
			printf("%s", struct_array[i]->month);
			printf("%3s ", struct_array[i]->day);
			printf("%5.5s ", struct_array[i]->time);
		}
		if (g_flags_ls->m && struct_array[i + 1])
			printf("%s, ", struct_array[i]->file_name);
		else
			printf("%s\n", struct_array[i]->file_name);
	}
}


