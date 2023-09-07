/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:00:33 by mkosemen          #+#    #+#             */
/*   Updated: 2022/11/21 15:23:27 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int n, int *len)
{
	if (n >= 0 && n <= 9)
		*len += ft_putchar(n + 48);
	if (n > 9)
	{
		ft_unsigned(n / 10, len);
		ft_unsigned(n % 10, len);
	}
	return (*len);
}
