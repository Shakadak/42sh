/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 16:06:00 by croy              #+#    #+#             */
/*   Updated: 2014/02/25 12:23:09 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsh.h"

size_t	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
	return (1);
}

size_t	ft_putstr_fd(char const *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
		i += ft_putchar_fd(str[i], fd);
	return (i);
}
