/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:31:45 by cheron            #+#    #+#             */
/*   Updated: 2013/11/29 17:42:13 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					ret;
	unsigned int		i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	ret = 0;
	str1 = s1;
	str2 = s2;
	while (i < n)
		{
			if (str1[i] != str2[i])
				{
					ret = ret + str1[i] - str2[i];
					return (ret);
				}
			i++;
		}
	return (ret);
}
