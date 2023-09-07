/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:37:30 by mkosemen          #+#    #+#             */
/*   Updated: 2022/11/01 18:14:43 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_word_check(const char *s, char c)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (result);
		while (s[i] != c && s[i] != '\0')
			i++;
		result++;
	}
	return (result);
}

static	int	ft_word_print(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**ft_split(const char *s, char c)
{
	char	**strlist;
	int		i;

	if (!s)
		return (0);
	i = 0;
	strlist = malloc(sizeof(char *) * (ft_word_check(s, c) + 1));
	if (!strlist)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			break ;
		strlist[i] = ft_substr(s, 0, ft_word_print(s, c));
		i++;
		s = s + ft_word_print(s, c);
	}
	strlist[i] = NULL;
	return (strlist);
}
