/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:46:25 by nmei              #+#    #+#             */
/*   Updated: 2017/11/30 14:01:09 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *big, const char *little)
{
	char *big_ptr;
	char *new_b_strt;
	char *lit_ptr;

	big_ptr = (char *)big;
	if (!*little)
		return (big_ptr);
	while (*big_ptr)
	{
		new_b_strt = big_ptr;
		lit_ptr = (char *)little;
		while (*big_ptr && *lit_ptr && *big_ptr == *lit_ptr)
		{
			big_ptr++;
			lit_ptr++;
		}
		if (!*lit_ptr)
			return (new_b_strt);
		big_ptr = new_b_strt + 1;
	}
	return (NULL);
}
