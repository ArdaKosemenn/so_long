/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkosemen <mkosemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:04:04 by mkosemen          #+#    #+#             */
/*   Updated: 2023/08/18 17:32:39 by mkosemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	secret_file(int ac, char *av)
{
	int	i;

	ac_control(ac);
	i = ft_strlen(av);
	i = 0;
	if (av[i] == '.')
	{
		ft_putstr_fd("SECRET FİLE\n", 2);
		exit(0);
	}
	while (av[i])
	{
		if (av[i] == '/')
		{
			if (av[i + 1] == '.' && av[i + 1] != '\0')
			{
				ft_putstr_fd("SECRET FİLE\n", 2);
				exit(0);
			}
		}
		i++;
	}
}
