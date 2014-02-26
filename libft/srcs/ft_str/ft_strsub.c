/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:57:15 by cheron            #+#    #+#             */
/*   Updated: 2014/01/21 14:57:11 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	end;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	end = start + len;
	str = ft_strnew(len + 1);
	if (str == NULL)
			return (NULL);
	while (start < end)
		{
			str[i] = s[start];
			start++;
			i++;
		}
	return (str);
}

