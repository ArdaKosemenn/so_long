/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:02:39 by mkosemen          #+#    #+#             */
/*   Updated: 2022/11/21 15:52:44 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upper(unsigned int n, int *len)
{
	if (n < 16)
	{
		if (n < 10)
			*len += ft_putchar(n + 48);
		else
			*len += ft_putchar(n + 55);
	}
	else
	{
		ft_upper(n / 16, len);
		ft_upper(n % 16, len);
	}
	return (*len);
}
