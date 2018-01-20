/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 09:24:25 by nmei              #+#    #+#             */
/*   Updated: 2017/11/30 16:10:27 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char *cs1;
	unsigned char *cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	if (n)
	{
		while ((*cs1 == *cs2) && --n)
		{
			if (*cs1 == '\0')
			{
				return (0);
			}
			cs1++;
			cs2++;
		}
		return ((int)(*cs1 - *cs2));
	}
	return (0);
}
