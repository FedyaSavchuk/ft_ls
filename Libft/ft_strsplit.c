/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hspeeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:13:32 by hspeeder          #+#    #+#             */
/*   Updated: 2019/09/07 21:13:35 by hspeeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_count_words(char const *s, char c)
{
	char	**arr;
	int		words;

	words = 0;
	while (*s)
	{
		if (*s != c)
			words++;
		while (*s != c && *s != '\0')
			s++;
		while (*s == c && *s != '\0')
			s++;
	}
	arr = (char **)malloc(sizeof(*arr) * words + 1);
	if (arr == NULL)
		return (NULL);
	return (arr);
}

static int	ft_len_word(char const *s, char c)
{
	int len;

	len = 0;
	while (*s == c && *s != '\0')
		s++;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len + 1);
}

static char	ft_check_null(char **arr, int i)
{
	if (arr[i] == NULL)
	{
		while (i >= 0)
			free(arr[i--]);
		free(arr);
		return (0);
	}
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	if (!s || !c)
		return (NULL);
	i = 0;
	if (!(arr = ft_count_words(s, c)))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		arr[i] = (char *)malloc(sizeof(char) * ft_len_word(s, c));
		if (ft_check_null(arr, i) == 0)
			return (NULL);
		if (ft_len_word(s, c) == 1)
			break ;
		j = 0;
		while (*s != c && *s != '\0')
			arr[i][j++] = *(s++);
		arr[i++][j] = '\0';
	}
	arr[i] = NULL;
	return (arr);
}
