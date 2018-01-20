/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:33:48 by nmei              #+#    #+#             */
/*   Updated: 2017/11/30 14:00:32 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		remainder;
	size_t		dlen;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	remainder = size;
	while (remainder-- != 0 && *d)
		d++;
	dlen = d - dst;
	remainder = size - dlen;
	if (remainder == 0)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (remainder != 1)
		{
			*d++ = *s;
			remainder--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
