/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 10:13:09 by nmei              #+#    #+#             */
/*   Updated: 2017/12/09 20:23:57 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	number_tochar(int num, int fd)
{
	int digit;
	int remainder;

	digit = num % 10;
	remainder = num / 10;
	if (remainder != 0)
	{
		number_tochar(remainder, fd);
		ft_putchar_fd('0' + ft_abs(digit), fd);
	}
	else
		ft_putchar_fd('0' + ft_abs(digit), fd);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
		ft_putchar_fd('-', fd);
	if (nb == 0)
		ft_putchar_fd('0', fd);
	else
		number_tochar(nb, fd);
}
