/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:54:19 by cheron            #+#    #+#             */
/*   Updated: 2013/11/29 17:38:24 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[i]);
	while (i > 0)
		{
			if (s[i - 1] == c)
				return ((char * )&s[i - 1]);
			i--;
		}
	return (NULL);
}
