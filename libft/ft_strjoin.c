/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:18:31 by nmei              #+#    #+#             */
/*   Updated: 2017/11/30 14:00:28 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_str;
	char	*temp;
	size_t	new_len;

	if (s1 && s2)
	{
		new_len = ft_strlen(s1) + ft_strlen(s2);
		join_str = NULL;
		join_str = (char *)malloc((new_len + 1) * sizeof(*join_str));
		if (join_str)
		{
			temp = join_str;
			while (*s1)
				*temp++ = *s1++;
			while (*s2)
				*temp++ = *s2++;
			*temp = '\0';
		}
		return (join_str);
	}
	return (NULL);
}
