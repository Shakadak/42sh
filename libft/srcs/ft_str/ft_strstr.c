/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:39:36 by cheron            #+#    #+#             */
/*   Updated: 2013/11/28 12:26:14 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *find)
{
	char	c;
	size_t	len;

	len = ft_strlen(find);
	while (ft_strncmp(s, find, len) != 0)
		{
			c = *s++;
			if (c == '\0')
				return (NULL);
		}
	return ((char *) s);
}
