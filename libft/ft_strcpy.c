/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 10:27:01 by nmei              #+#    #+#             */
/*   Updated: 2017/12/09 18:27:15 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** A more verbose but equivalent method would be:
** while ((*dest++ = *src++) != '\0')
*/

char	*ft_strcpy(char *dest, char *src)
{
	char *dest_start;

	dest_start = dest;
	while ((*dest++ = *src++))
		;
	return (dest_start);
}
