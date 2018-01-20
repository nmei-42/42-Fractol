/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:19:14 by nmei              #+#    #+#             */
/*   Updated: 2017/12/14 22:18:38 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static char		**allocate_words(char **result, char *str, char sep)
{
	int ind;
	int w_len;
	int w_ind;

	ind = 0;
	w_len = 0;
	w_ind = 0;
	while (str[ind] == sep)
		ind++;
	while (str[ind++] != '\0')
	{
		w_len++;
		if ((str[ind] == sep) || str[ind] == '\0')
		{
			if ((result[w_ind] = (char*)malloc(sizeof(**result) * (w_len + 1))))
			{
				w_ind++;
				w_len = 0;
				while (str[ind] == sep)
					ind++;
			}
		}
	}
	return (result);
}

static char		**fill_result(char **result, char *str, char sep)
{
	int index;
	int w_pos;
	int word_index;

	index = 0;
	w_pos = 0;
	word_index = 0;
	while (str[index] == sep)
		index++;
	while (str[index] != '\0')
	{
		result[word_index][w_pos] = str[index];
		index++;
		w_pos++;
		if (str[index] == sep)
		{
			result[word_index][w_pos] = '\0';
			word_index++;
			w_pos = 0;
			while (str[index] == sep)
				index++;
		}
	}
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	num_words;

	result = NULL;
	if (s)
	{
		num_words = ft_num_words(s, c);
		if ((result = (char**)malloc(sizeof(*result) * (num_words + 1))))
		{
			result = allocate_words(result, (char *)s, c);
			result = fill_result(result, (char *)s, c);
			result[num_words] = NULL;
		}
	}
	return (result);
}
