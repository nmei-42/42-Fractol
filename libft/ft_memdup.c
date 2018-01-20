/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:17:36 by nmei              #+#    #+#             */
/*   Updated: 2017/11/30 13:59:34 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	*ft_memdup(void const *src, size_t size)
{
	void *dup;

	if (!(dup = malloc(size)))
		return (NULL);
	ft_memcpy(dup, src, size);
	return (dup);
}
