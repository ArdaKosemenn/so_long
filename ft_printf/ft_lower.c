/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:03:00 by mkosemen          #+#    #+#             */
/*   Updated: 2022/11/21 15:52:53 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lower(unsigned int n, int *len)
{
	if (n < 16)
	{
		if (n < 10)
			*len += ft_putchar(n + 48);
		else
			*len += ft_putchar(n + 87);
	}
	else
	{
		ft_lower(n / 16, len);
		ft_lower(n % 16, len);
	}
	return (*len);
}
