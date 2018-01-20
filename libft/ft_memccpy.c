/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:38:34 by nmei              #+#    #+#             */
/*   Updated: 2017/11/30 13:59:20 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**	First assign value of src_ptr to dst_ptr then check if dst_ptr == c
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dst_ptr;
	unsigned char *src_ptr;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (n--)
	{
		if ((*dst_ptr++ = *src_ptr++) == (unsigned char)c)
			return (dst_ptr);
	}
	return (NULL);
}
