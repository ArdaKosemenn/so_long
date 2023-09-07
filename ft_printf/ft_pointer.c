/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:08:34 by mkosemen          #+#    #+#             */
/*   Updated: 2022/11/21 15:47:28 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long long i, int *len)
{
	if (i < 16)
	{
		if (i < 10)
		{
			*len += ft_putchar(i + 48);
		}
		else
			*len += ft_putchar(i + 87);
	}
	else
	{
		ft_pointer(i / 16, len);
		ft_pointer(i % 16, len);
	}
	return (*len);
}
