/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:26:46 by mkosemen          #+#    #+#             */
/*   Updated: 2022/11/21 18:04:16 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_func(char s, va_list *args)
{
	int	len;

	len = 0;
	if (s == 'c')
		len += ft_putchar(va_arg(*args, int));
	else if (s == 'd')
		ft_putnbr(va_arg(*args, int), &len);
	else if (s == 's')
		len += ft_putstr(va_arg(*args, char *));
	else if (s == 'u')
		ft_unsigned(va_arg(*args, unsigned int), &len);
	else if (s == 'i')
		ft_putnbr(va_arg(*args, int), &len);
	else if (s == '%')
		len += write(1, "%", 1);
	else if (s == 'x')
		ft_lower(va_arg(*args, unsigned int), &len);
	else if (s == 'X')
		ft_upper(va_arg(*args, unsigned int), &len);
	else if (s == 'p')
	{
		len += write(1, "0x", 2);
		ft_pointer(va_arg(*args, unsigned long long), &len);
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, s);
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_func(s[i], &args);
		}
		else
		{
			len += ft_putchar(s[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
