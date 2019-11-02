/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolen <aolen@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:02:15 by aolen             #+#    #+#             */
/*   Updated: 2019/09/07 18:40:35 by aolen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isdelim(char c, char delim)
{
	if (c == delim || c == '\0')
		return (1);
	return (0);
}

static int		count_words(const char *str, char delim)
{
	int words_num;
	int i;

	words_num = 0;
	i = 0;
	while (str[i])
	{
		if ((!ft_isdelim(str[i], delim) && i == 0) ||
			(ft_isdelim(str[i - 1], delim) && !ft_isdelim(str[i], delim)))
			words_num += 1;
		i++;
	}
	return (words_num);
}

static char		**clear_list(char ***words, int num)
{
	while (num > -1)
	{
		free(*words[num]);
		*words[num] = NULL;
		num--;
	}
	free(*words);
	*words = NULL;
	return (*words);
}

static char		**ft_split(const char *str, int words_num, char delim, int j)
{
	int		i;
	int		k;
	char	**words;

	i = -1;
	if (!(words = (char**)malloc(sizeof(*words) * (words_num + 1))))
		return (NULL);
	while (str[++i] && words_num)
		if ((!ft_isdelim(str[i], delim) && i == 0) ||
			(ft_isdelim(str[i - 1], delim) && !ft_isdelim(str[i], delim)))
		{
			k = 0;
			while (!ft_isdelim(str[i + k], delim))
				k++;
			if (!(words[j] = (char*)malloc(sizeof(**words) * (k + 1))))
				return (clear_list(&words, j - 1));
			words[j][k--] = 0;
			while (k >= 0)
			{
				words[j][k] = str[i + k];
				k--;
			}
			j++;
		}
	return (words);
}

char			**ft_strsplit(const char *s, char c)
{
	int		words_num;
	char	**words;

	if (s == NULL)
		return (NULL);
	words_num = count_words(s, c);
	if (!(words = ft_split(s, words_num, c, 0)))
		return (NULL);
	words[words_num] = NULL;
	return (words);
}
