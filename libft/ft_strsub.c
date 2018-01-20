/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:08:49 by nmei              #+#    #+#             */
/*   Updated: 2017/11/30 14:01:12 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	ind;

	if (s)
	{
		ind = 0;
		sub_str = NULL;
		sub_str = (char *)malloc((len + 1) * sizeof(*sub_str));
		if (sub_str)
		{
			while (ind < len)
			{
				sub_str[ind] = s[start + ind];
				ind++;
			}
			sub_str[ind] = '\0';
		}
		return (sub_str);
	}
	return (NULL);
}
