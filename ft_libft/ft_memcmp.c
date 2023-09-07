/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:32:27 by mkosemen          #+#    #+#             */
/*   Updated: 2022/11/01 12:17:15 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*k;
	unsigned char	*m;

	k = (unsigned char *)s1;
	m = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((k[i]) != (m[i]))
			return ((k[i]) - (m[i]));
		i++;
	}
	return (0);
}
