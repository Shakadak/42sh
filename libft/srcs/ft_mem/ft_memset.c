/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:35:49 by cheron            #+#    #+#             */
/*   Updated: 2013/12/05 14:06:50 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;
	size_t			i;

	i = 0;
	d = b;
	while (i < len)
	{
		d[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
