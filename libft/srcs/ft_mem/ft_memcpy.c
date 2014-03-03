/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:34:38 by cheron            #+#    #+#             */
/*   Updated: 2013/11/29 17:34:47 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*src;

	dest = s1;
	i = 0;
	src = s2;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (s1);
}
