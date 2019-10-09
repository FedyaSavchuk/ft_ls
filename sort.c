#include "ft_ls.h"

l_file		**sort_by_ascii(l_file **struct_array)
{
	int i;
	int j;
	l_file *temp;

	i = 1;
	while (struct_array[i])
	{
		j = i - 1;
		temp = struct_array[i];
		while (j >= 0 && ft_strcmp(struct_array[j]->file_name, temp->file_name) > 0)
		{
			struct_array[j + 1] = struct_array[j];
			j--;
		}
		struct_array[j + 1] = temp;
		i++;
	}
	return (struct_array);
}

l_file		**sort_by_time(l_file **struct_array)
{
	int i;
	int j;
	l_file	*temp;

	i = 1;
	while (struct_array[i])
	{
		j = i - 1;
		temp = struct_array[i];
		while (j >= 0 && struct_array[j]->unix_time - temp->unix_time < 0)
		{
			struct_array[j + 1] = struct_array[j];
			j--;
		}
		struct_array[j + 1] = temp;
		i++;
	}
	return (struct_array);
}

l_file		**sort_by_size(l_file **struct_array)
{
	int i;
	int j;
	l_file	*temp;

	i = 1;
	while (struct_array[i])
	{
		j = i - 1;
		temp = struct_array[i];
		while (j >= 0 && struct_array[j]->file_size - temp->file_size > 0)
		{
			struct_array[j + 1] = struct_array[j];
			j--;
		}
		struct_array[j + 1] = temp;
		i++;
	}
	return (struct_array);
}
