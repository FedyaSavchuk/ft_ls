#include "ft_ls.h"

//l_file		*swap_list_elem(l_file *files)
//{
//	if
//}

l_file		**sort_by_ascii(l_file **struct_array)
{
	int 	flag;
	int 	i;
	int 	k;
	l_file	*temp;

	i = 0;
	while (struct_array[i])
	{
		flag = 0;
		k = 0;
		if (struct_array[i]->file_name[k] > struct_array[i + 1]->file_name[k])
		{
			temp = struct_array[i];
			struct_array[i] = struct_array[i + 1];
			struct_array[i + 1] = temp;
			flag = 1;
		}
		while (struct_array[i]->file_name[k] == struct_array[i + 1]->file_name[k]
		&& (struct_array[i]->file_name[k] || struct_array[i + 1]->file_name[k]))
		{
			k++;
			if (struct_array[i]->file_name[k] > struct_array[i + 1]->file_name[k])
			{
				temp = struct_array[i];
				struct_array[i] = struct_array[i + 1];
				struct_array[i + 1] = temp;
				flag = 1;
				break;
			}
		}
		i++;
		if (flag == 1)
			i = 0;
	}
	return (struct_array);
}

//l_file		*sort_by_time(l_file *files)
//{
//
//}