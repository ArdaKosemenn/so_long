/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:54:54 by mkosemen          #+#    #+#             */
/*   Updated: 2023/08/12 16:20:16 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	m;
	char	*result;

	i = 0;
	result = (char *)haystack;
	if (!needle[i])
		return (result);
	else if (len == 0)
		return (0);
	while (result[i] != '\0' && i < len)
	{
		m = 0;
		while ((needle[m] && result[i + m] == needle[m] && (i + m < len)))
			m++;
		if (needle[m] == '\0')
			return (&result[i]);
		i++;
	}
	return (0);
}
