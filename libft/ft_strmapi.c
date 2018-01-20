/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:49:32 by nmei              #+#    #+#             */
/*   Updated: 2017/11/30 14:00:42 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map_str;
	char			*start;
	unsigned int	len;
	unsigned int	ind;

	if (s && (*f))
	{
		len = (unsigned int)ft_strlen(s);
		ind = 0;
		map_str = (char *)malloc((len + 1) * sizeof(*map_str));
		if (map_str)
		{
			map_str[len] = '\0';
			start = map_str;
			while (ind < len)
			{
				*map_str++ = (*f)(ind++, *s++);
			}
			return (start);
		}
	}
	return (NULL);
}
