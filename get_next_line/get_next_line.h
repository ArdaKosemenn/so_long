/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:57:00 by mkosemen          #+#    #+#             */
/*   Updated: 2023/07/07 16:51:13 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		fft_strlen(const char *s);
char	*fft_strjoin(char *s1, char *s2);
int		fft_strchr(char *str, char c);
char	*ft_next_line(char *str);
char	*ft_linechecker(char *str);
char	*fft_reader(int fd, char *str);
char	*get_next_line(int fd);
#endif