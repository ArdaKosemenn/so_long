/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:03:18 by mkosemen          #+#    #+#             */
/*   Updated: 2022/11/21 15:23:39 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		*len += ft_putchar('-');
		*len += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		*len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		*len += ft_putchar(n + 48);
	if (n > 9)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	return (*len);
}
