/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelickel <kelickel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:33:30 by kelickel          #+#    #+#             */
/*   Updated: 2014/03/25 17:32:30 by kelickel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if (s == 0)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putstr_fd(char const *s, int fd)
{
	if (s == 0)
		return ;
	write(fd, s, ft_strlen(s));
}
