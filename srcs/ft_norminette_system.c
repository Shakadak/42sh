/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norminette_system.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:35:12 by croy              #+#    #+#             */
/*   Updated: 2014/03/27 16:43:53 by croy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_in_norme(char **ded, char *tmp, int fd)
{
	if ((fd = open(tmp, O_RDONLY)) == -1)
		write(2, "Can't open file\n", 17);
	else
	{
		dup2(fd, 0);
		if (ded[0] != 0)
			ft_system(ded[0]);
	}
	free(tmp);
}
