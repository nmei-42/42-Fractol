/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:36:59 by nmei              #+#    #+#             */
/*   Updated: 2017/11/30 14:01:01 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	const char *last_match;

	last_match = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_match = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	if (last_match)
		return ((char *)last_match);
	return (NULL);
}
