/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:22:39 by mkosemen          #+#    #+#             */
/*   Updated: 2022/10/27 14:25:56 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*hamper;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	hamper = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!hamper)
		return (0);
	while (s1[i] != '\0')
	{
		hamper[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
		hamper[j++] = s2[i++];
	hamper[j] = '\0';
	return (hamper);
}
