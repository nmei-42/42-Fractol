/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:21:43 by nmei              #+#    #+#             */
/*   Updated: 2017/11/30 13:59:38 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**	memmove checks if dst and src overlap
**	If our dst is longer than source + 'len to copy' then we can just
**	blindly copy forward as with memcpy.
**
**	However, if our dst is shorter than source + 'len to copy' then
**	we should copy from the 'end' (i.e. from dst + len back to dst).
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *end;
	unsigned char *src_ptr;
	unsigned char *dst_ptr;

	if ((size_t)dst - (size_t)src >= len)
		return (ft_memcpy(dst, src, len));
	else
	{
		end = (unsigned char *)dst;
		src_ptr = (unsigned char *)src + len;
		dst_ptr = (unsigned char *)dst + len;
		while (dst_ptr != end)
			*--dst_ptr = *--src_ptr;
	}
	return (dst);
}
