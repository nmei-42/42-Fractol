/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 21:31:49 by nmei              #+#    #+#             */
/*   Updated: 2017/12/14 21:34:48 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_splitdel(char ***split)
{
	char	**str;
	int		i;

	i = 0;
	if (split)
	{
		str = *split;
		while (*str)
		{
			ft_strdel(str);
			i++;
			str = &(*split)[i];
		}
		ft_memdel((void **)split);
	}
}
