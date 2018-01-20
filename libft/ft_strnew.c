/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:06:52 by nmei              #+#    #+#             */
/*   Updated: 2017/11/30 14:00:55 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*new_str;

	new_str = NULL;
	new_str = (char *)malloc((size + 1) * sizeof(char));
	if (new_str)
		ft_memset(new_str, '\0', size + 1);
	return (new_str);
}
