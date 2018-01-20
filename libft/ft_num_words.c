/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:26:59 by nmei              #+#    #+#             */
/*   Updated: 2017/12/14 22:18:40 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_num_words(const char *str, char sep)
{
	size_t	num_words;

	num_words = 0;
	while (*str == sep)
		str++;
	while (*str != '\0')
	{
		str++;
		if (*str == sep)
		{
			num_words++;
			while (*str == sep)
				str++;
		}
	}
	if (!(*(str - 1) == sep) && *(str - 1))
		num_words++;
	return (num_words);
}
