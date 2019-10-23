
#include "ft_ls.h"
#include <stdio.h>

struct ls_sizes
{
	int link_len;
	int	size_len;
	int user_len;
	int block_len;
	int group_len;
	int maj_len;
	int minor_len;
}	g_ls_sizes;

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
		if ((!g_flags_ls->a && !g_flags_ls->f) && struct_array[i]->file_name[0] == '.')
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
		else if (column == 'm')
			len = int_len(struct_array[i]->maj);
		else if (column == 'i')
			len = int_len(struct_array[i]->min);
		if (max_len < len)
			max_len = len;
	}
	return (max_len);
}

void	print_l(l_file *struct_el)
{
	if (g_flags_ls->s)
		printf("%*d ", g_ls_sizes.block_len, struct_el->st_blocks);
	printf("%-12s", struct_el->chmod);
	printf("%*d ", g_ls_sizes.link_len, struct_el->nlink);
	if (!(g_flags_ls->g))
		printf("%-*s  ", g_ls_sizes.user_len, struct_el->user_name);
	printf("%-*s  ", g_ls_sizes.group_len, struct_el->group);
	if (struct_el->chmod[0] != 'c' && struct_el->chmod[0] != 'b')
		printf("%*d ", g_ls_sizes.size_len, struct_el->file_size);
	else
		printf("%*d, %*d ", g_ls_sizes.maj_len + 1,
			   struct_el->maj, g_ls_sizes.minor_len,
			   struct_el->min);
	printf("%s", struct_el->date);
	printf("%5.5s ", struct_el->time);
}

void	print_ls(l_file **struct_array, char *dir_name, int r_flag, int f)
{
	int i;

	i = -1;
	g_ls_sizes.link_len = max_len(struct_array, 'l');
	g_ls_sizes.size_len = max_len(struct_array, 'f');
	g_ls_sizes.user_len = max_len(struct_array, 'u');
	g_ls_sizes.block_len = max_len(struct_array, 'b');
	g_ls_sizes.group_len = max_len(struct_array, 'g');
	g_ls_sizes.maj_len = max_len(struct_array, 'm');
	g_ls_sizes.minor_len = max_len(struct_array, 'i');
	if (g_ls_sizes.maj_len + g_ls_sizes.minor_len + 2 > g_ls_sizes.size_len &&
			g_ls_sizes.maj_len + g_ls_sizes.minor_len != 2)
		g_ls_sizes.size_len = g_ls_sizes.maj_len + g_ls_sizes.minor_len + 3;
	if (r_flag)
		printf("\n%s:\n", dir_name);
	if (g_flags_ls->l && !f && (struct_array[i + 3] || g_flags_ls->a))
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
			print_l(struct_array[i]);
//			if (g_flags_ls->s)
//				printf("%*d ", block_len, struct_array[i]->st_blocks);
//			printf("%-12s", struct_array[i]->chmod);
//			printf("%*d ", link_len, struct_array[i]->nlink);
//			if (!(g_flags_ls->g))
//				printf("%-*s  ", user_len, struct_array[i]->user_name);
//			printf("%-*s  ", max_len(struct_array, 'g'), struct_array[i]->group);
//			if (struct_array[i]->chmod[0] != 'c' && struct_array[i]->chmod[0] != 'b')
//				printf("%*d ", size_len, struct_array[i]->file_size);
//			else
//				printf("%*d, %*d ", int_len(struct_array[i]->min),
//						struct_array[i]->min, int_len(struct_array[i]->maj),
//						struct_array[i]->maj);
//			printf("%s", struct_array[i]->date);
//			printf("%5.5s ", struct_array[i]->time);
		}
		if (g_flags_ls->m && (struct_array[i + 1] || f))
			printf("%s, ", struct_array[i]->file_name);
		else
			printf("%s\n", struct_array[i]->file_name);//, !struct_array[i + 1] && f ? '\n' : 1);
	}
}

void print_directory(char *filename)
{
	if (opendir(filename))
		printf("%s:\n", filename);
	else
		printf("%s:\n", filename);
}

