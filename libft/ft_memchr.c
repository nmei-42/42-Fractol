/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:47:22 by nmei              #+#    #+#             */
/*   Updated: 2017/11/30 13:59:23 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *src_ptr;

	src_ptr = (unsigned char *)s;
	while (n--)
	{
		if (*src_ptr == (unsigned char)c)
			return (src_ptr);
		src_ptr++;
	}
	return (NULL);
}
