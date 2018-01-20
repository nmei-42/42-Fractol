/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:19:28 by nmei              #+#    #+#             */
/*   Updated: 2017/12/01 13:22:23 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstlast(t_list *begin_list)
{
	t_list	*curr_list;

	curr_list = begin_list;
	if (curr_list)
	{
		while (curr_list->next)
		{
			curr_list = curr_list->next;
		}
	}
	return (curr_list);
}
