/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:34:57 by mkosemen          #+#    #+#             */
/*   Updated: 2023/08/12 16:19:24 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	buff = malloc(sizeof(char) * (fft_strlen(str) - i + 1));
	i++;
	if (!buff)
		return (NULL);
	j = 0;
	while (str[i])
		buff[j++] = str[i++];
	buff[j] = '\0';
	free(str);
	return (buff);
}

char	*ft_linechecker(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*fft_reader(int fd, char *str)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = 1;
	while ((fft_strchr(str, '\n')) && i != 0)
	{
		i = read(fd, s, BUFFER_SIZE);
		if (i == -1)
		{
			free(s);
			return (0);
		}
		s[i] = '\0';
		str = fft_strjoin(str, s);
	}
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = fft_reader(fd, str);
	if (!str)
		return (0);
	result = ft_linechecker(str);
	str = ft_next_line(str);
	return (result);
}
