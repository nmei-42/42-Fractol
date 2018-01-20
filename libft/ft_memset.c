/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:06:20 by nmei              #+#    #+#             */
/*   Updated: 2017/12/15 23:13:04 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *s, int c, size_t len)
{
	typedef unsigned long	t_ulong;
	unsigned char			*cp;
	t_ulong					*lp;
	t_ulong					word;

	cp = s;
	c = c & 0xFF;
	while (len && (((t_ulong)cp & (sizeof(t_ulong) - 1)) != 0))
	{
		*(cp++) = (unsigned char)c;
		len--;
	}
	lp = (t_ulong *)((void *)cp);
	word = (t_ulong)c << 24 | (t_ulong)c << 16 | (t_ulong)c << 8 | (t_ulong)c;
	word = word << 32 | word;
	while (len > sizeof(t_ulong))
	{
		*(lp++) = word;
		len -= sizeof(t_ulong);
	}
	cp = (unsigned char *)((void *)lp);
	while (len--)
		*(cp++) = (unsigned char)c;
	return (s);
}
